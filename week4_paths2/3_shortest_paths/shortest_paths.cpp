#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  long long inf = INT64_MAX;
  int v = adj.size();
  vector<long long> dist(v, INT64_MAX);
  dist[s] = 0;
    for (int i = 1; i <= v-1; i++) { 
      for (int j = 0; j < v; j++) {
        for(int k = 0; k < adj[j].size(); k++){ 
          int from = j; 
          int to = adj[j][k]; 
          int weight = cost[j][k]; 
          if (dist[from] != inf && dist[from] + weight < dist[to]) 
              dist[to] = dist[from] + weight; 
      } }
    }
    vector<long long> dist2 = dist;
    // vth step of Bellman Ford
    for(int i = 0; i < 5; i++)
    for (int j = 0; j < v; j++) {
        for(int k = 0; k < adj[j].size(); k++){ 
          int from = j; 
          int to = adj[j][k]; 
          int weight = cost[j][k]; 
          if (dist[from] != inf && dist[from] + weight < dist[to]) 
              dist[to] = dist[from] + weight; 
    } }

    for(int x = 0; x < v; x++){
      if(dist[x] != inf){
      reachable[x] = 1;  
      if (dist[x] !=  dist2[x])
        shortest[x] = 0; 
      else 
        distance[x] = dist[x]; 
      }
    }
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, INT64_MAX);
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}

// 5 4 1 2 1 4 1 2 2 3 2 3 1 -5 4
/*
6 7
1 2 10
2 3 5
1 3 100
3 5 7
5 4 10
4 3 -18
6 1 -1
1
*/