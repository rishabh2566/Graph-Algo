#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int isvisited[1005] = {0};
int label = 0;
int number_of_components(vector<vector<int> > &adj, int x) {
  //write your code here
  if(isvisited[x] == 0){
    isvisited[x] = label;
    for(int i = 0; i < adj[x].size(); i++){
      number_of_components(adj, adj[x][i]);
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  for(int i = 0; i < n; i++){
    if(isvisited[i] == 0){
        label++;
        number_of_components(adj,i);
    }
  }
  std::cout<<label;
  return 0;
}
