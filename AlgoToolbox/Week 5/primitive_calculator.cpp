#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> parent(n+1,0);
  vector<int> dp(n+1,0);
  for(int i=2;i<=n;i++){
    int q1=INT_MAX,q2=INT_MAX,q3=dp[i-1];
    if(i%2==0)q1=dp[i/2];
    if(i%3==0) q2=dp[i/3];
    int min_val=min(q1,min(q2,q3));
    dp[i]=min_val+1;
    if(min_val==q2) parent[i]=i/3;
    else if (min_val==q1) parent[i] = i / 2;
    else  parent[i] = i -1;
  }
  vector<int> sequence;
  int ans=n;
  while(ans>=1){
    sequence.emplace_back(ans);
    ans=parent[ans];
  }
  reverse(sequence.begin(),sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
