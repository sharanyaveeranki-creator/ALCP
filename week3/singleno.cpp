#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int &x : a)
        cin >> x;

    int ans = 0;

    for (int x : a)
        ans ^= x;

    cout << "Single number = " << ans << endl;

    return 0;
}