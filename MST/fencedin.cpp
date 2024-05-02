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
class UFDS{
    vi p, rank;
public:
    UFDS(int n){
        p.assign(n,0);
        rank.assign(n,0);
        for(int i=0; i < n; i++) p[i]=i;
    }
    int findSet(int i){
        return p[i]==i? i: p[i]=findSet(p[i]);
    }
    bool isSameSet(int i, int j){
        return findSet(i)==findSet(j);
    }
    void unionSet(int i, int j){
        if(isSameSet(i,j)) return;
        int x= findSet(i), y= findSet(j);
        if(rank[x] > rank[y]) swap(x,y);
        p[x]= y;
        if(rank[x]==rank[y]) rank[y]++;
    }
};
struct Edge{
    int u, v, w;
};
void solve(){
    int a,b, n, m; cin>>a >> b >> n >> m;
    vi ver(n+1), hor(m+1);
    for(int i=1; i <= n; i++) cin>>ver[i];
    for(int i=1; i <= m; i++) cin>>hor[i];
    ver.push_back(b);
    hor.push_back(a);
    sort(all(ver));
    sort(all(hor));
    n+=2, m+=2;
    int row=1, cur=0;
    vector<Edge> edges;
    while(row < n){
        for(int i=0; i < m-2; i++){
            edges.push_back({cur, cur+1, ver[row]-ver[row-1]});
            cur++;
        }
        cur++;
        row++;
    }
    cur= m-1;
    int col=1;
    while(col < m){
        int init= cur;
        for(int i=0; i < n-2; i++){
            edges.push_back({cur-(m-1), cur, hor[col]-hor[col-1]});
            cur+=(m-1);
        }
        cur= init+1;
        col++;
    }
    UFDS UF((n+2)*(m+2));
    sort(all(edges), [](Edge a, Edge b){
        return a.w < b.w;
    });
    ll ans=0;
    for(auto e: edges){
        if(!UF.isSameSet(e.u,e.v)){
            UF.unionSet(e.u,e.v);
            ans+= e.w;
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; t=1;
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    while(t--){
        solve();
    }
}
