#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<pair<int, int>> G[N];
bool vis[N];
int prims(){
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
    int source = 1;
    int res = 0;
    for(auto child: G[source]){
        pq.push({child.second, child.first});
    }
    vis[source] = 0;
    while(!pq.empty()){
        auto e = pq.top();
        pq.pop();
        int curr = e.second;
        if(vis[curr]) continue;
        vis[curr] = true;
        res += e.first;
        for(auto child: G[curr]){
            int v = child.first;
            if(vis[v]) continue;
            pq.push({child.second, v});
        }
    }
    return res;
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<m; ++i){
        int u, v, w;
        cin>>u>>v>>w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    cout<<prims()<<endl;
}
