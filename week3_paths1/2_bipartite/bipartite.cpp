#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using namespace std;
int bipartite(vector<vector<int> > &adj) {
  int N = adj.size();
  bool visited[N];
  int distance[N];
  for(int i = 0; i < N; i++){
    visited[i] = false;
    distance[i] = -1;
  }
  for(int i = 0; i < N; i++){ 
  if(!visited[i]){
  queue<int> q;
  q.push(i); distance[i] = 0; visited[i] = 1;
  while(!q.empty()){
    int s = q.front(); q.pop();
  for (auto u : adj[s]) {
    if (visited[u]) {
      if ( (distance[s] - distance[u]) % 2 == 0) return 0;
      continue;
    }
    visited[u] = true;
    distance[u] = distance[s]+1;
    q.push(u);
  }
  }}}
return 1;
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
  std::cout << bipartite(adj);
}
