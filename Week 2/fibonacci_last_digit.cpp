#include <iostream>
#include<vector>
using namespace std;

long long int get_fibonacci_last(long long int n) {
   vector<long long int> dp(n+1,0);
    dp[1]=1;
    for (int i = 2; i <=n ; ++i) {
        dp[i]=(dp[i-1]+dp[i-2])%10;
    }

    return dp[n]%10;
}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last(n);
    cout << c << '\n';
}
