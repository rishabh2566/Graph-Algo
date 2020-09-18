#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<int> > &adj, vector<bool> &visited, vector<int> &order, int x) {
  
    visited[x] = 1;
    for(int i = 0; i < adj[x].size(); i++ ){
      if(!visited[adj[x][i]]){
        dfs(adj, visited, order, adj[x][i]);
      }
    }
    order.push_back(x);
  
}   

int number_of_strongly_connected_components(vector<vector<int> >& adj, vector<vector<int> >& adjR) {
  int result = 0;
  int n = adj.size();
  vector<int> postorder;
  vector<bool> visitedR(n, 0);
  vector<bool> visited(n, 0);
  for(int i = 0; i < n; i++){
    if(!visited[i])
      dfs(adj, visited, postorder, i);
  }

  reverse(postorder.begin(), postorder.end());

  for(int i = 0; i < n; i++){
  	int v = postorder[i];
    if(!visitedR[v]){
      result++;
      vector<int> scc;
      dfs(adjR, visitedR, scc , v);
    }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > adjR(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adjR[y - 1].push_back(x - 1);
  }
  std::cout << number_of_strongly_connected_components(adj,adjR);
  return 0;
}
