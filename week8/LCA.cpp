#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* lca(Node* root, int a, int b) {
    if (!root)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    Node* left = lca(root->left, a, b);
    Node* right = lca(root->right, a, b);

    if (left && right)
        return root;

    return left ? left : right;
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int a, b;

    cout << "Enter first node: ";
    cin >> a;

    cout << "Enter second node: ";
    cin >> b;

    Node* ans = lca(root, a, b);

    if (ans)
        cout << "LCA = " << ans->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}