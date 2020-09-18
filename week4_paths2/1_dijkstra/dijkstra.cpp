#include <iostream>
#include <vector>
#include <queue>
#include <utility> 

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;


int distance(vector<vector<pair<int,int> > > &adj, int s, int t) {
	int n = adj.size();
	int distance[n];
	bool processed[n];
	for (int i = 1; i <= n; i++){
	distance[i] = 1e9;
	processed[i] = false;
	}
	distance[s] = 0;
	priority_queue<pair<int,int> > q;
	q.push({0,s});
	while(!q.empty()) {
		int a = q.top().second; q.pop();
		if (processed[a]) continue;
		processed[a] = true;
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (distance[a]+w < distance[b]) {
				distance[b] = distance[a]+w;
				q.push({-distance[b],b});
			}
		}
	}	
return  processed[t] ? distance[t] : -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<pair<int,int> > > adj(n, vector<pair<int,int> >());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back({y - 1, w});
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
