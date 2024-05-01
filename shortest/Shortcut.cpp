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
vii gr[10005];
void solve(){
    int n, m, t; cin>>n>>m>>t;
    vi c(n);
    for(int i=0; i<n; i++) cin>>c[i];
    for(int i=0; i<m; i++) {
        int u, v, w; cin>> u>> v>> w;
        u--; v--;
        gr[u].emplace_back(v,w);
        gr[v].emplace_back(u,w);
    }
    vector<int> dist(n, INT32_MAX);
    vector<int> prev(n, -1);
    priority_queue<ii, vii, greater<ii>> pq;
    dist[0]=0;
    pq.emplace(0,0);
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [v, w]: gr[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                prev[v]=u;
                pq.emplace(dist[v], v);
            }
            else if(dist[v]==dist[u]+w && prev[v]>u){
                prev[v]=u;
                pq.emplace(dist[v], v);
            }
        }
    }
    vector<ll> cnt(n);
    for(int i=0; i < n; i++){
        int cur=i;
        while(cur!=-1){
            cnt[cur]+=c[i];
            cur=prev[cur];
        }
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        ans=max(ans, cnt[i]*(dist[i]-t));
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; t=1;
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    while(t--){
        solve();
    }
}
