#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int finish;
};

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> a(n);

    cout << "Enter start and finish times:" << endl;

    for (auto &x : a)
        cin >> x.start >> x.finish;

    sort(a.begin(), a.end(), [](Activity x, Activity y) {
        return x.finish < y.finish;
    });

    int lastFinish = -1;

    cout << "Selected activities: ";

    for (auto x : a) {
        if (x.start >= lastFinish) {
            cout << "(" << x.start << "," << x.finish << ") ";
            lastFinish = x.finish;
        }
    }

    return 0;
}