#include <iostream>
#include <vector>
#include <queue>
#include <utility> 
#include <set>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;


int dijkstra(vector<vector<pair<int,int> > > &adj, int s, int t) {
  set< pair<int, int> > mindist;
  int inf = INT32_MAX;
  int n = adj.size();
  int dist[n];
  for(int i = 0; i < n; i++)
    dist[i] = inf;
  dist[s] = 0;
  mindist.insert(make_pair(0,s));

  while(!mindist.empty()){
    pair<int, int> tmp = *(mindist.begin()); 
    mindist.erase(mindist.begin()); 

    int u = tmp.second;
    for(auto x : adj[u]){
      int v = x.first;
      int weight = x.second;
      if( dist[v] > dist[u] + weight){
        if(dist[v] != inf){
          mindist.erase(mindist.find(make_pair(dist[v], v)));
        }
        dist[v] = dist[u] + weight; 
        mindist.insert(make_pair(dist[v], v)); 
      }
    }
  }   // end of while, we have path to all nodes;

  return dist[t] == inf ? -1 : dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<pair<int,int> > > adj(n, vector<pair<int,int> >());
  // Adj list is...
  // from -> {To , Weight}
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back({y - 1, w});
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << dijkstra(adj, s, t);
  return 0;
}