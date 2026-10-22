#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity: ";
    cin >> W;

    vector<int> weight(n), value(n);

    cout << "Enter weights: ";
    for (int &x : weight)
        cin >> x;

    cout << "Enter values: ";
    for (int &x : value)
        cin >> x;

    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weight[i]; w--) {
            dp[w] = max(dp[w],
                        dp[w - weight[i]] + value[i]);
        }
    }

    cout << "Maximum profit = " << dp[W] << endl;

    return 0;
}