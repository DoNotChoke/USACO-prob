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
int dp[100005][21][3];
void solve(){
    int n, k; cin>> n>> k;
    vi a(n);
    for(int i=0; i < n; i++){
        char c; cin>> c;
        if(c=='H') a[i]=0;
        if(c=='P') a[i]=1;
        if(c=='S') a[i]=2;
    }
    if(a[0]==0) dp[0][0][1]=1;
    if(a[0]==1) dp[0][0][2]=1;
    if(a[0]==2) dp[0][0][0]=1;
    for(int i=1; i < n; i++){
        for(int j=0; j <= min(i,k); j++){
            for(int l=0; l < 3; l++){
                if((a[i]==0 and l==1) or (a[i]==1 and l==2) or (a[i]==2 and l==0)){
                    dp[i][j][l]= dp[i-1][j][l]+1;
                    if(j>0){
                        for(int m=0; m < 3; m++){
                            if(m!=l){
                                dp[i][j][l]= max(dp[i][j][l], dp[i-1][j-1][m]+1);
                            }
                        }
                    }
                }
                else dp[i][j][l]= dp[i-1][j][l];
            }
        }
    }
    cout<<max({dp[n-1][k][0], dp[n-1][k][1], dp[n-1][k][2]})<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; t=1;
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    while(t--){
        solve();
    }
}
