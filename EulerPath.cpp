#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
vector<int> G[N], ans;
int done[N];
void dfs(int u)
{
    while (done[u] < G[u].size())
        dfs(G[u][done[u]++]);
    ans.push_back(u);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> in(n + 1, 0), out(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        out[u]++;
        in[v]++;
    }
    int ok = 1, cnt1 = 0, cnt2 = 0, root = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] - out[i] == 1)
            cnt1++;
        if (out[i] - in[i] == 1)
            cnt2++, root = i;
        if (abs(in[i] - out[i]) > 1)
            ok = 0;
    }
    if (cnt1 > 1 || cnt2 > 1)
        ok = 0;
    if (!ok)
    {
        cout << 0 << endl;
        return;
    }
    if (root == 0)
    {
        for (int i = 1; i <= n; i++)
            if (out[i])
                root = i;
    }
    if (root == 0)
    {
        cout << 1 << endl;
        return;
    }
    dfs(root);
    if (ans.size() != m + 1)
    {
        cout << 0 << endl;
        return;
    }
    reverse(ans.begin(), ans.end());
    for (auto val : ans)
        cout << val << ' ';
    cout << endl;
    return;
}
int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
