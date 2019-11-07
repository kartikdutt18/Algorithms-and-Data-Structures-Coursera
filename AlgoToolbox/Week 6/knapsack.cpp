#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int optimal_weight(int W, const vector<int> &w)
{
  vector<vector<int>> dp(W + 1, vector<int>(w.size() + 1, 0));
  for (int i = 1; i <= W; i++)
  {
    for (int j = 1; j <= w.size(); j++)
    {
      dp[i][j] = dp[i][j - 1];
      if (w[j - 1] <= i)
      {
        int temp = dp[i - w[j - 1]][j - 1] + w[j - 1];
        if (dp[i][j] < temp)
          dp[i][j] = temp;
      }
    }
  }
  return dp[W][w.size()];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
