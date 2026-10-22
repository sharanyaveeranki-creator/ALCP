#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= mid)
        temp.push_back(a[i++]);

    while (j <= high)
        temp.push_back(a[j++]);

    for (int i = 0; i < temp.size(); i++)
        a[low + i] = temp[i];
}

void mergeSort(vector<int>& a, int low, int high) {
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    mergeArray(a, low, mid, high);
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int &x : a)
        cin >> x;

    mergeSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : a)
        cout << x << " ";

    return 0;
}