#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<pair<int,int>> v;
  for(int i=0;i<weights.size();i++){
    v.push_back({weights[i],values[i]});
  }
  auto compare= [](auto a,auto b){return 1.*a.second/a.first>1.*b.second/b.first;};
  sort(v.begin(),v.end(),compare);
  int i=0;
  while(capacity>0 && i<weights.size()){
    value+=min(capacity,v[i].first)*(1.*v[i].second/v[i].first);
    capacity -= min(capacity, v[i].first);
    i++;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
