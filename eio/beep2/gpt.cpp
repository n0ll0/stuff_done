#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAXN = 3e5+5;
vector<int> adj[MAXN]; // adjacency list of the tree
int depth[MAXN];       // depth of each vertex in the tree
int first_occur[MAXN]; // first occurrence of each vertex in the DFS order
vector<int> dfs_order; // DFS order of the tree

void dfs(int u, int parent)
{
  first_occur[u] = dfs_order.size();
  dfs_order.push_back(u);
  for (int v : adj[u])
  {
    if (v != parent)
    {
      depth[v] = depth[u] + 1;
      dfs(v, u);
      dfs_order.push_back(u);
    }
  }
}

struct Node
{
  int vertex;
  int depth;
  Node(int v, int d) : vertex(v), depth(d) {}
};

int LCA(int u, int v)
{
  int l = first_occur[u], r = first_occur[v];
  if (l > r)
    swap(l, r);
  int k = log2(r - l);
  Node a(dfs_order[l + (1 << k) - 1], depth[dfs_order[l + (1 << k) - 1]]);
  Node b(dfs_order[r - (1 << k) + 1], depth[dfs_order[r - (1 << k) + 1]]);
  if (a.depth < b.depth)
    return a.vertex;
  else
    return b.vertex;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  for (int i = 1; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  int q;
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    int u, v;
    cin >> u >> v;
    cout << LCA(u, v) << "\n";
  }

}