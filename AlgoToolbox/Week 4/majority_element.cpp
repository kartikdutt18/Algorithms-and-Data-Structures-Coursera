#include<bits/stdc++.h>
using namespace std;


int get_majority_element(vector<int> &a, int left, int right) {
  map<int,int> ht;
  for(auto i:a){
    ht[i]+=1;
  }
  for(auto i: ht){
    if(i.second>a.size()/2) return 1;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
