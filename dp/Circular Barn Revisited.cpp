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
ll dist[105][105];
ll dp[105][10];
void solve(){
    int n, k; cin>> n>> k;
    vi a(n);
    for(int i=0; i < n; i++) cin>> a[i];
    ll ans= 1e9;
    for(int i=0; i < n; i++){
        ll sum=0;
        int d=1;
        int j= (i+1)%n;
        while(j != i){
            dist[i][j]= sum;
            sum+= d*a[j];
            d++;
            j= (j+1)%n;
        }
        if(k==1)
        ans= min(ans, sum);
    }
    if(k==1){
        cout<< ans<< "\n";
        return;
    }
    for(int st=0; st < n; st++){
        for(int i=0; i < n; i++){
            for(int j=0; j <= k; j++)
                dp[i][j]= 1e9;
        }
        dp[st][1]=0;
        int ed= (st+1)%n;
        while(ed != st){
            for(int c=2; c <= k; c++){
                for(int prev= 0; prev < n; prev++){
                    dp[ed][c]= min(dp[ed][c], dp[prev][c-1]+ dist[prev][ed]);
                }
                if(c==k){
                    dp[ed][c]+= dist[ed][st];
                    ans= min(ans, dp[ed][c]);
                }
            }
            ed= (ed+1)%n;
        }
    }
    cout<< ans<< "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; t=1;
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    while(t--){
        solve();
    }
}
