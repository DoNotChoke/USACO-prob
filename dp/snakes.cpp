#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<pair<int,int>> vii;
#define ll long long
#define ld long double
#define LSONE(s)  (s&-(s))
#define all(v) v.begin(), v.end()
#define mod (ll)(1e9+7)
#define inf (ll)(1e18)
int dp[405][405];
void solve(){
    int n, k; cin>> n>> k;
    vi a(n);
    for(int i=0; i < n; i++)
        for(int j=0; j<= k; j++)
            dp[i][j]= 1e9;
    for(int i=0; i<n; i++) cin>> a[i];
    int maxo= -1;
    int sum=0;
    for(int i=0; i < n; i++){
        maxo= max(maxo, a[i]);
        dp[i][0]= (i+1)*maxo;
        for(int j=1; j <= k; j++){
            int tmp= a[i];
            for(int l= i-1; l >= 0; l--){
                dp[i][j]= min(dp[i][j], dp[l][j-1]+ tmp*(i-l));
                tmp= max(tmp, a[l]);
            }
        }
        sum+= a[i];
    }
    cout<<dp[n-1][k]-sum<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; t=1;
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    while(t--){
        solve();
    }
}
