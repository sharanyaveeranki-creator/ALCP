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

void dfs(Node* root) {
    if (!root)
        return;

    cout << root->data << " ";

    dfs(root->left);
    dfs(root->right);
}

void bfs(Node* root) {
    if (!root)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        cout << cur->data << " ";

        if (cur->left)
            q.push(cur->left);

        if (cur->right)
            q.push(cur->right);
    }
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "DFS: ";
    dfs(root);

    cout << endl;

    cout << "BFS: ";
    bfs(root);

    return 0;
}