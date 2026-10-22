#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int result = 1;

    cout << "Enter power: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        result *= 2;

    cout << "2^" << n << " = " << result << endl;

    return 0;
}