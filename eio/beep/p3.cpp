using std
struct Node {
  vector<int> pars;
  int depth;
};

constexpr int H = 20;

Node nodes[300005];

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  intn;
  cin >> n;
  for (int i = 0; i<n-1;++i) {
    int u,v;
    cin >> u>> v;
    nodes[u].conn.insert(v);
    nodes[v].conn.insert(u);
  }

  vector<int> stack;
  stack;

  while (!stack.empty()) {
    int curr = stack.back();
    stack.pop_back();

    auto &cn = nodes[curr];
    for (auto o: cn.conn){
      auto &on = nodes[o];
      on.pars.push_back(curr);
      on.conn.erase(curr);
      on.depth=cn.depth+1;
      stack.push_back(o);
    }
  }

  for (int h=0;h<H;++h){
    for(inti=1;i<=n;++i){
      auto &cn=nodes[i];
      if (cn.pars.size()>h){
        auto &par=nodes[cn.pars[h]];
        if (par.pars.size()>h){
          cn.pars.
        }
      }
    }
  }
  return 0;
}
