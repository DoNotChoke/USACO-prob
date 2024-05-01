#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<pair<int,int>> vii;
#define ll long long
#define ld long double
#define LSONE(s)  (s&-(s))
#define all(v) v.begin(), v.end()
#define mod (ll)(1e9+9)
#define inf (ll)(1e18)
ll dp[1005][1005][11];
void solve(){
    int n, m, k; cin>> n>> m>> k;
    vi a(n), b(m);
    for(auto &i: a) cin>> i;
    for(auto &i: b) cin>> i;
    sort(all(a));
    sort(all(b));
    for(int i=0; i <= n; i++)
        for(int j=0; j <= m; j++)
            dp[i][j][0]=1;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            for(int s=1; s <= k; s++){
                dp[i+1][j+1][s]= (dp[i+1][j][s]+ dp[i][j+1][s])%mod;
                dp[i+1][j+1][s]-= dp[i][j][s];
                dp[i+1][j+1][s]+= mod;
                dp[i+1][j+1][s]%= mod;
                if(a[i] > b[j]){
                    dp[i+1][j+1][s]+= dp[i][j][s-1];
                }
                dp[i+1][j+1][s]+= mod;
                dp[i+1][j+1][s]%= mod;
            }
    cout<< dp[n][m][k]<< endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; t=1;
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    while(t--){
        solve();
    }
}
