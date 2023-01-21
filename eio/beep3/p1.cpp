#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAXN = 3e5;
vector<int> adj[MAXN]; 
int depth[MAXN];       
int first_occur[MAXN]; 
vector<int> dfs_order; 

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
  int k = log2(r - l + 1);
  Node node_2k(dfs_order[l + (1 << k) - 1], depth[dfs_order[l + (1 << k) - 1]]);
  Node node_2k_2(dfs_order[r - (1 << k) + 1], depth[dfs_order[r - (1 << k) + 1]]);
  if (node_2k.depth < node_2k_2.depth)
    return node_2k.vertex;
  else
    return node_2k_2.vertex;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;


  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0); 

  int q;
  cin >> q;
  vector<int> ans;

  for (int i = 0; i < q; i++)
  {
    int u, v;
    cin >> u >> v;
    cout << LCA(u, v) << "\n";
  }

}

/*
5
1 2
1 3
3 4
3 5
5
1 2
1 3
2 3
4 1
4 5


*/