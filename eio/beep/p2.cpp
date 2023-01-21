#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
const int N = 300000;

vector<int> edges[N];
int db[N][20];

void dfs(int u, int p)
{
  db[u][0] = p;
  for (int v : edges[u])
  {
    if (v!=p)
    {
      dfs(v, u);
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i=1;n>=i;i++)
  {
    int u,v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int j = 1; j <= log2(n); j++)
  {
    for (int i = 1; i <= n; i++)
    {
      db[i][j] = db[db[i][j - 1]][j - 1];
    }
  }
  int Q;
  cin >> Q;
  dfs(1,0);
  for (int i = 0; i < Q; i++) 
  {
    int u,k;
    cin >> u >> k;
    for (int j=19; j>=0;j--)
    {
      if (k >= (1 << j))
      {
        k -= (1 << j);
        u = db[u][j];
      }
    }
    cout << u << "\n";
  }
  return 0;
}