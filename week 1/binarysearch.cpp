#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> target;

    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == target) {
            ans = mid;
            break;
        }
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (ans != -1)
        cout << "Element found at index " << ans << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}