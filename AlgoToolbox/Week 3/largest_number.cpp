#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string largest_number(vector<string> a) {
  auto compare=[](auto a,auto b){return a+b>b+a;};
  sort(a.begin(),a.end(),compare);
  string largest_num="";
  for(auto i:a) largest_num+=i;
  return largest_num;
}

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
   cin >> a[i];
  }
  cout << largest_number(a);
}
