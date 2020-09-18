#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> now;
vector<bool> visited;
int flag = 0;

int acyclic(vector<vector<int> > &adj, int v) {
  now[v] = 1;
  visited[v] = 1;
  for(int i =0; i < adj[v].size(); i++){
    if(now[ adj[v][i] ]) flag = 1;
    if(!visited[ adj[v][i] ])
      acyclic(adj, adj[v][i]);
  }
  now[v] = 0;
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  for(int i = 0; i < n; i++){
    now.push_back(false);
    visited.push_back(false);
  }
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  for(int i = 0; i < n; i++ ){
    if(!visited[i]) acyclic(adj, i);
  }
  std::cout << flag;
  return 0;
}
