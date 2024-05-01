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
vector<pair<int,ii>> gr[1005];
int n, m;
int dijkstra(int flow){
    priority_queue<ii, vii, greater<ii>> pq;
    pq.emplace(0,0);
    vector<int> dist(n, 1e9);
    dist[0]=0;
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(dist[u] < d) continue;
        for(auto [v, w] : gr[u]){
            if(w.second < flow) continue;
            if(dist[v] > d+w.first){
                dist[v] = d+w.first;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist[n-1];
}
void solve(){
    cin>> n>> m;
    set<int> flow;
    for(int i=0; i < m; i++){
        int u,v,c,f; cin>> u>> v>>c>> f;
        u--; v--;
        gr[u].push_back({v,{c,f}});
        gr[v].push_back({u,{c,f}});
        flow.insert(f);
    }
    int ans= -1;
    for(int f: flow) {
        int d = dijkstra(f);
        if (d == 1e9) continue;
        double ratio= double(f)/ (double)d;
        ans= max(ans, (int)(ratio*1000000));
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; t=1;
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    while(t--){
        solve();
    }
}
