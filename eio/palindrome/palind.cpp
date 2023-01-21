#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 50000;

vector<int> adj[MAXN + 5];
int flow[MAXN + 5][MAXN + 5], cap[MAXN + 5][MAXN + 5];
int pre[MAXN + 5], dist[MAXN + 5];
bool vis[MAXN + 5];
int N, M, S, T;

bool bfs() {
    for (int i = 0; i <= N + 1; i++) {
        dist[i] = INT_MAX;
        vis[i] = false;
    }
    dist[S] = 0;
    vis[S] = true;
    queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INT_MAX && flow[u][v] < cap[u][v]) {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return vis[T];
}

int dfs(int u, int f) {
    if (u == T) return f;
    int res = 0;
    for (int v : adj[u]) {
        if (dist[v] == dist[u] + 1 && flow[u][v] < cap[u][v]) {
            int t = dfs(v, min(f, cap[u][v] - flow[u][v]));
            if (t > 0) {
                flow[u][v] += t;
                flow[v][u] -= t;
                res += t;
                f -= t;
                if (f == 0) break;
            }
        }
    }
    return res;
}

int dinic() {
    int maxflow = 0;
    while (bfs()) {
        maxflow += dfs(S, INT_MAX);
    }
    return maxflow;
}

int main() {
    cin >> N >> M;
    S = 0, T = N + 1;
    int total_cost = 0;
    for (int i = 0; i < M; i++) {
        int x, s;
        cin >> x >> s;
        total_cost += s;
        adj[x].push_back(T);
        adj[T].push_back(x);
        flow[x][T] = 0;
        cap[x][T] = s;
    }
    for (int i = 1; i <= N; i++) {
        adj[S].push_back(i);
        adj[i].push_back(S);
        flow[S][i] = 0;
        cap[S][i] = total_cost / N;
    }
    int maxflow = dinic();
    cout << total_cost - maxflow << endl;
    vector<tuple<int, int, int>> ans;
    for (int i = 1; i <= N; i++) {
        for (int j : adj[i]) {
            if (j != S && flow[i][j] > 0) {
                ans.push_back({i, j, flow[i][j]});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto t : ans) {
        int x = get<0>(t);
        int y = get<1>(t);
        int s = get<2>(t);
        cout << x << " " << y - N << " " << s << endl;
    }
    return 0;
}

