#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;

  return gcd(b, a % b);
}
long long int lcm(int a,int b){
  return (a*b)/gcd(a,b);
}
int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm(a, b) <<endl;
  return 0;
}
