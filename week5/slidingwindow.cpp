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

    cout << "Enter window size: ";
    cin >> k;

    int sum = 0;

    for (int i = 0; i < k; i++)
        sum += a[i];

    int maximum = sum;

    for (int i = k; i < n; i++) {
        sum += a[i];
        sum -= a[i - k];
        maximum = max(maximum, sum);
    }

    cout << "Maximum window sum = " << maximum << endl;

    return 0;
}