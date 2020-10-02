#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  int n = x.size();
  vector<int> visited(n,0); // index of visited node
  visited[0] = 1;
  vector<pair<double, int> > dist;
  for(int i = 1; i < n; i++){
    double d = sqrt( pow(x[0]-x[i],2) + pow(y[0]-y[i],2) ); 
    dist.push_back(make_pair(d,i));
  }
  sort(dist.begin(), dist.end());
  reverse(dist.begin(), dist.end());

  while(!dist.empty()){
    int i = dist.back().second; 
    double path = dist.back().first;
    dist.pop_back();
    for(int j = 0; j < n; j++){
      if(visited[j]){
      double d = sqrt( pow(x[j]-x[i],2) + pow(y[j]-y[i],2) ); 
      path = min(path, d);
    }}
    result += path;
    visited[i] = 1;
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << fixed << std::setprecision(8) << minimum_distance(x, y) << std::endl;
}


// 4 0 0 0 1 1 0 1 1
// 5 0 0 0 2 1 1 3 0 3 2