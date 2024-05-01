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
vector<ii> gr[50005];
vector<int> dist;
void dijkstra(int s){
    priority_queue<ii,vector<ii> , greater<ii>> pq;
    pq.emplace(0,s);
    dist[s]=0;
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w] : gr[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}
void solve(){
    int n, m, k ; cin>> n >> m >> k;
    vector<int> id(k), val(k);
    vector<int> dist_last(n, 1e9);
    vector<int> dist_hay(n, 1e9);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for(int i=0; i<m; i++){
        int u, v, w; cin>> u >> v >> w;
        u--; v--;
        gr[u].emplace_back(v, w);
        gr[v].emplace_back(u, w);
    }
    dist.assign(n,1e9);
    dijkstra(n-1);
    for(int i=0; i < k; i++){
        cin>> id[i]>> val[i];
        id[i]--;
    }
    vector<int> d= dist;
    dist.assign(n+1,1e9);
    for(int i=0; i < k; i++){
        gr[n].emplace_back(id[i], d[id[i]] - val[i]);
        gr[id[i]].emplace_back(n, d[id[i]] - val[i]);
    }
    dijkstra(n);
    for(int i=0; i < n-1; i++)
        cout<<(dist[i] <= d[i])<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    int t; t=1;
    while(t--){
        solve();
    }
}
