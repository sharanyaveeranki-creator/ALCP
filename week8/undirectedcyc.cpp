#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent,
         vector<vector<int>>& graph,
         vector<bool>& visited) {

    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next]) {
            if (dfs(next, node, graph, visited))
                return true;
        }
        else if (next != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n);

    cout << "Enter edges:" << endl;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n, false);
    bool cycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, graph, visited)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "Cycle exists" << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}