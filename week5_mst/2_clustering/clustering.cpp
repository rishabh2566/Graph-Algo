#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
  
    // Constructor. 
    DisjointSets(int n) 
    { 
        // Allocate memory 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        // Initially, all vertices are in 
        // different sets and have rank 0. 
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
  
            //every element is parent of itself 
            parent[i] = i; 
        } 
    } 
  
    // Find the parent of a node 'u' 
    // Path Compression 
    int find(int u) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    // Union by rank 
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
  
        /* Make tree with smaller height 
           a subtree of the other tree  */
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else // If rnk[x] <= rnk[y] 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 


double clustering(int n, vector<int> x, vector<int> y, int k) {
	// input
	vector< pair<double , pair<int,int> > > list;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			double edge = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
			if(edge != 0){
				list.push_back(make_pair(edge, make_pair(i,j)));
			}
		}
	}

	sort(list.begin(), list.end());

	// Create disjoint sets 
    DisjointSets ds(n); 
	double edge = 0; int edgecount = 0;
	int list_it = 0;
    while (edgecount < n-k+1) 
    { 
        int u = list[list_it].second.first; 
        int v = list[list_it].second.second; 
  
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
  
        // if not forming cycle
        if (set_u != set_v) 
        { 
            // Merge two sets 
            ds.merge(set_u, set_v); 

            edge = list[list_it].first;
            edgecount++;
        } 
        list_it++;
    }

	return edge;
} 

int main() {
	size_t n;
	int k;
	std::cin >> n;
	vector<int> x(n), y(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::cin >> k;
	std::cout << fixed<<std::setprecision(9) << clustering(n, x, y, k) << std::endl;
}

/*
8
3 1
1 2
4 6
9 8
9 9
8 9
3 11
4 12
4
Output : 5 [Correct]
*/

