#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"enter no. of elements:";
    cin >> n;

    double sum = 0, x;
    cout<<"enter elements:";
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }

    cout << "Sum = " << sum << endl;
    cout << "Average = " << sum / n << endl;

    return 0;
}