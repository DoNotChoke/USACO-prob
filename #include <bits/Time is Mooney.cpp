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
vi gr[10005];
vi regr[10005];
int dp[1005][1005];
void solve(){
   int n, m, c; cin>> n>> m>> c;
   vi earn(n);
   for(int i=0; i < n; i++) cin>> earn[i];
   for(int i=0; i < m; i++){
       int u, v; cin>> u>> v;
       u--; v--;
       gr[u].push_back(v);
       regr[v].push_back(u);
   }
   for(int i=0; i < n; i++)
       for(int d=0; d <= 1000; d++)
           dp[i][d]= -1e9;
   dp[0][1]= 0;
   for(int d= 2; d <= 1000; d++){
       for(int i=0; i < n; i++){
           for(int j: regr[i]){
               dp[i][d]= max(dp[i][d], dp[j][d-1]+ c*(d-2)*(d-2)- c*(d-1)*(d-1) + earn[i]);
           }
       }
   }
    int ans= -1e9;
    for(int d=1; d <= 1000; d++)
        ans= max(ans, dp[0][d]);
    cout<< ans<< endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; t=1;
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    while(t--){
        solve();
    }
}
