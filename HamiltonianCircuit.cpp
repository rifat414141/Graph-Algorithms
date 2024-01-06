#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 20;
bool adj[N][N];
bool dp[(1 << N)][N];
bool vis[(1 << N)][N];
int link[N];
int n, m;
bool path_exists(int mask, int node) // Using masked Nodes to visit node as final
{
    if (vis[mask][node])
    {
        return dp[mask][node];
    }
    vis[mask][node] = true;
    int mask2 = (mask & ~(1 << node));
    if (mask2 == 0)
    {
        // Base condition (Single Node)
        return dp[mask][node] = adj[n][node]; // If the beginning can be reached from the Saved Node
    }
    for (int i = 0; i < n; ++i)
    {
        if (mask2 & (1 << i)) // Available
        {
            if (adj[i][node] && path_exists(mask2, i))
            {
                link[node] = i; // For printing
                return dp[mask][node] = true;
            }
        }
    }
    return dp[mask][node] = false;
}
void solve()
{
    // Hamiltonian Circuit
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        // u--, v--; // Making 0 Based
        adj[u][v] = adj[v][u] = true;
    }
    int w = n - 1; // Saving the final node
    n--;
    int mask = (1 << n) - 1; // (111...) of size n
    int last = -1;
    for (int i = 0; i < n; ++i)
    {
        if (path_exists(mask, i) && adj[i][w])
        {
            // cout << i << endl;
            last = i;
            // break;
        }
    }
    if (last == -1)
    {
        cout << "No Path Found!" << endl;
    }
    else
    {
        cout << n << ' ';
        for (int i = 0; i < n; ++i)
        {
            cout << last << ' ';
            int next = link[last];
            // mask &= ~(1 << last);
            last = next;
        }
        cout << n << ' ';
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
