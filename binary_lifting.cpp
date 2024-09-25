#include <bits/stdc++.h>
#define int long long int
const int INF = 2e18;
using namespace std;
const int N = 2e6 + 10;
const int LOGN = 30;
vector<int> G[N];
int up[N][LOGN];
void dfs(int u, int p)
{
    for (auto v : G[u])
    {
        if (v == p)
            continue;
        up[v][0] = u;
        for (int i = 1; i < LOGN; ++i)
            up[v][i] = up[up[v][i - 1]][i - 1];
        dfs(v, u);
    }
}
int get_kth(int u, int k)
{
    int res = u;
    for (int i = LOGN; i >= 0; --i)
        if ((1 << i) & k)
            res = up[res][i];
    return res;
}
int get_lca(int a, int b)
{
    if (depth[b] > depth[a])
        swap(a, b);
    a = get_kth(a, depth[a] - depth[b]);
    if (a == b)
        return a;
    for (int i = LOGN - 1; i >= 0; --i)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int u, k;
        cin >> u >> k;
        cout << get_kth(u, k) << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
