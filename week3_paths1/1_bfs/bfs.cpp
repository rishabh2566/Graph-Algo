#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using namespace std;
int distance(vector<vector<int> > &adj, int s, int t) {
  queue<int> q;
  int N = adj.size();
  bool visited[N];
  int distance[N];
  for(int i = 0; i < N; i++){
    distance[i] = -1;
    visited[i] = false;
  }
  visited[s] = true;
  distance[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int s = q.front(); q.pop();
    for (auto u : adj[s]) {
      if (visited[u]) continue;
      visited[u] = true;
      distance[u] = distance[s]+1;
      q.push(u);
    } 
  }
  return distance[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
