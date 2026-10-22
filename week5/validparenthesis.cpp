#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    cout << "Enter parentheses: ";
    cin >> s;

    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                cout << "Invalid parentheses" << endl;
                return 0;
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                cout << "Invalid parentheses" << endl;
                return 0;
            }
        }
    }

    if (st.empty())
        cout << "Valid parentheses" << endl;
    else
        cout << "Invalid parentheses" << endl;

    return 0;
}