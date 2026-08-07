#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    vector<int> ans(n, -1);

    cout << "Enter elements: ";
    for (int &x : a)
        cin >> x;

    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= a[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();

        st.push(a[i]);
    }

    cout << "Next greater elements: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}