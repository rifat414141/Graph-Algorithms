#include <bits/stdc++.h>
#define ll long long int
#define INF 1e8;
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int sz[N];
void Make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int Find(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = Find(parent[v]);
}
void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}
void Kruskals()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; ++i)
        Make(i);
    int total = 0;
    for (auto p : edges)
    {
        int wt = p.first;
        int u = p.second.first;
        int v = p.second.second;
        if (Find(u) == Find(v))
            continue;
        total += wt;
        Union(u, v);
    }
    cout << total << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // prec();
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        Kruskals();
    }
    return 0;
}
