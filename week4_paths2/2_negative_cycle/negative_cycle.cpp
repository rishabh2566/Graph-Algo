#include <iostream>
#include <vector>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost, vector<int> &visited, int s) {
  //write your code here
  int v = adj.size();
  vector<int> dist(v,INT32_MAX);
  dist[s] = 0;
  for (int i = 1; i <= v - 1; i++) { 
        for (int j = 0; j < v; j++) {
          for(int k = 0; k < adj[j].size(); k++){ 
            int from = j; 
            int to = adj[j][k]; 
            int weight = cost[j][k]; 
            if (dist[from] != INT32_MAX && dist[from] + weight < dist[to]) 
                dist[to] = dist[from] + weight; 
        } }
    }
    for (int j = 0; j < v; j++) {
          for(int k = 0; k < adj[j].size(); k++){ 
            int from = j; 
            int to = adj[j][k]; 
            int weight = cost[j][k]; 
            if (dist[from] != INT32_MAX && dist[from] + weight < dist[to]) 
                return 1;
        } }
    for(int i = 0; i < v; i++)
      if(dist[i] != INT32_MAX)
        visited[i] = 1;

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  vector<int> visited(n,0);
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      if(negative_cycle(adj,cost,visited,i)){
        std::cout<<1;
        return 0;
      }
    }
  }
  std::cout << 0;
  return 0;
}

//4 4 1 2 -5 4 1 2 2 3 2 3 1 1