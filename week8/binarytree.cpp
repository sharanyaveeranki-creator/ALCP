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

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    queue<Node*> q;
    q.push(root);

    cout << "Level order traversal:" << endl;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            Node* cur = q.front();
            q.pop();

            cout << cur->data << " ";

            if (cur->left)
                q.push(cur->left);

            if (cur->right)
                q.push(cur->right);
        }

        cout << endl;
    }

    return 0;
}