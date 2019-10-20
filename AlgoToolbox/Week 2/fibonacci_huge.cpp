#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//We know period starts with zero and one
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//We know period starts with zero and one

vector<int> pisano(int n)
{
    vector<int> v;
    int current = 0, next = 1;

    v.push_back(current);

    if (n < 2)
        return v;
    current = (next += current) - current;

    while (current != 0 || next != 1)
    {
        v.push_back(current);
        current = current + next >= n ? (next += current - n) + (n - current) : (next += current) - current;
    }

    return v;
}

int main()
{
    long long int n, m;
    cin >> n >> m;
    vector<int> v = pisano(m);
    cout << v[n % v.size()] << endl;
}