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
int a[30][30];
int dp[100005][30];
int cnt[100005][30];
int pre(int l, int r, int c){
    return cnt[r+1][c]- cnt[l][c];
}
void solve(){
    int n, m, k; cin>> n>> m>> k;
    string s; cin>> s;
    for(int i=0; i < m; i++)
        for(int j=0; j < m; j++)
            cin>> a[i][j];
    for(int t=0; t < m; t++){
        for(int i=0; i < m; i++){
            for(int j=0; j < m; j++){
                a[i][j] = min(a[i][j], a[i][t] + a[t][j]);
            }
        }
    }
    for(int i=1; i <= n; i++){
        for(int j=0; j < m; j++){
            cnt[i][j]= cnt[i-1][j]+ (s[i-1]-'a' == j);
        }
    }
    vector<int> ans(n+1);
    for(int i= k-1; i < min(2*k-1, n); i++){
        for(int j=0; j < m; j++){
            for(int t=0; t < m; t++){
                dp[i][j]+= a[t][j]* pre(0,i, t);
            }
        }
        ans[i]= dp[i][0];
        for(int j=1; j < m; j++){
            ans[i]= min(ans[i], dp[i][j]);
        }
    }
    for(int i= 2*k-1; i < n; i++){
        for(int j=0; j < m; j++){
            dp[i][j]= dp[i-1][j]+ a[s[i]-'a'][j];
        }
        for(int j=0; j < m; j++){
            int add=0;
            for(int t=0; t < m; t++){
                add+= a[t][j]* pre(i-k+1, i, t);
            }
            dp[i][j]= min(dp[i][j], ans[i-k]+ add);
        }
        ans[i]= dp[i][0];
        for(int j=1; j < m; j++){
            ans[i]= min(ans[i], dp[i][j]);
        }
    }
    cout<<ans[n-1]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    int t; t=1;
    while(t--){
        solve();
    }
}
