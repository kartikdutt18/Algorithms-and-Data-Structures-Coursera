#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int edit_distance(const string &word1, const string &word2)
{
  int len1 = word1.length(), len2 = word2.length();
  if (len1 == 0 && len2 != 0)
  {
    return len2;
  }
  else if (len2 == 0 && len1 != 0)
  {
    return len1;
  }
  int ed[len1 + 1][len2 + 1];
  for (int i = 0; i <= len1; i++)
  {
    for (int j = 0; j <= len2; j++)
    {
      if (i == 0)
      {
        ed[i][j] = j;
      }
      else if (j == 0)
      {
        ed[i][j] = i;
      }
      else if (word1[i - 1] == word2[j - 1])
      {
        ed[i][j] = ed[i - 1][j - 1];
      }
      else
      {
        ed[i][j] = min(ed[i - 1][j - 1], min(ed[i - 1][j], ed[i][j - 1])) + 1;
      }
    }
  }
  return ed[len1][len2];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
