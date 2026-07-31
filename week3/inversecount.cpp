#include <bits/stdc++.h>
using namespace std;

long long mergeArray(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;
    int i = low;
    int j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else {
            temp.push_back(a[j++]);
            count += mid - i + 1;
        }
    }

    while (i <= mid)
        temp.push_back(a[i++]);

    while (j <= high)
        temp.push_back(a[j++]);

    for (int i = 0; i < temp.size(); i++)
        a[low + i] = temp[i];

    return count;
}

long long inversionCount(vector<int>& a, int low, int high) {
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    long long count = 0;

    count += inversionCount(a, low, mid);
    count += inversionCount(a, mid + 1, high);
    count += mergeArray(a, low, mid, high);

    return count;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int &x : a)
        cin >> x;

    cout << "Inversion count = "
         << inversionCount(a, 0, n - 1) << endl;

    return 0;
}