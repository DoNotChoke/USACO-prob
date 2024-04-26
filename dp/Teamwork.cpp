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
int dp[100005];
void solve(){
    int n, k; cin>> n>> k;
    vi a(n);
    for(int i=0; i < n; i++) cin>> a[i];
    memset(dp, -1, sizeof dp);
    for(int i=0; i < n; i++){
        int cur= a[i];
        for(int j=i; j >= (i-k+1) and j >= 0; j--){
            cur= max(cur, a[j]);
            if(j > 0)
            dp[i]= max(dp[i], dp[j-1]+ cur*(i-j+1));
            else dp[i]= max(dp[i], cur*(i-j+1));
        }
    }
    cout<<dp[n-1]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; t=1;
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    while(t--){
        solve();
    }
}
