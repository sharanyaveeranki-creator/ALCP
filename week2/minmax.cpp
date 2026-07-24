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

    int mn = a[0];
    int mx = a[0];

    for (int x : a) {
        mn = min(mn, x);
        mx = max(mx, x);
    }

    cout << "Minimum = " << mn << endl;
    cout << "Maximum = " << mx << endl;

    return 0;
}