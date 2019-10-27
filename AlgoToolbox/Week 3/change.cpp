#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int get_change(int m) {
  vector<int> coins={1,5,10};
  vector<int> dp(m+11,INT_MAX);
  dp[0]=0;
  dp[1]=1;
  dp[5]=1;
  dp[10]=1;
  for(int i=2;i<=m;i++){
    for(auto j:coins){
      if(i-j>=0)
        dp[i]=min(dp[i],dp[i-j]+1);
    }
  }
  return dp[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
  return 0;
}
