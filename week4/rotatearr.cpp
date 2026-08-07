#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int &x : a)
        cin >> x;

    cout << "Enter rotation count: ";
    cin >> k;

    k %= n;

    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());

    cout << "Rotated array: ";
    for (int x : a)
        cout << x << " ";

    return 0;
}