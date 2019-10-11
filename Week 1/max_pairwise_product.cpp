#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    sort(numbers.begin(),numbers.end());
    cout<<numbers[n-1]*numbers[n-2]<<endl;
    
    return 0;
}
