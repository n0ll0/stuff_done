#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 300005;

vector<int> edges[N];
int dp[N][20];

void dfs(int u, int p) {
  dp[u][0] = p;
  for (int v : edges[u]) {
    if (v != p) dfs(v, u);
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1, 0);
  for (int j = 1; j <= log2(n); j++)
  {
    for (int i = 1; i <= n; i++)
    {
      dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }
  }
  int q;
  cin >> q;
  int out[q];
  for (int i = 0; i < q; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 19; j >= 0; j--)
    {
      if (k >= (1 << j))
      {
        k -= (1 << j);
        u = dp[u][j];
      }
    }
    out[i] = u;
  }
  for (int o: out)
  {
    cout << o << endl;
  }
  return 0;
}