#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int i=1;
  int sum=n;
  while(i<=n && sum>0){
    if(( sum-i>i || sum==i ) && sum-i<=n){
      summands.emplace_back(i);
      sum-=i;
    }
    i++;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
