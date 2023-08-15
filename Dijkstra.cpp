#include <bits/stdc++.h>
#define ll long long int
#define INF 1e8;
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, int>> G[N];
bool vis[N];
int dist[N];
void dijkstra(int source)
{
    dist[source] = 0;
    set<pair<int, int>> st;
    st.insert({0, source});
    while (!st.empty())
    {
        auto p = *st.begin();
        int wt = p.first;
        int vertex = p.second;
        st.erase(st.begin());
        if (vis[vertex])
            continue;
        vis[vertex] = true;
        for (auto child : G[vertex])
        {
            int ch = child.first;
            int ch_wt = child.second;
            if (wt + ch_wt < dist[ch])
            {
                dist[ch] = wt + ch_wt;
                st.insert({dist[ch], ch});
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
    {
        vis[i] = false;
        dist[i] = INF;
        G[i].clear();
    }
    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }
    dijkstra(1);
    if (dist[n] == 1e8)
        cout << "Impossible" << endl;
    else
        cout << dist[n] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // prec();
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}
