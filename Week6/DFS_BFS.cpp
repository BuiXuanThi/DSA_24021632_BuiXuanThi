#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Ham them canh
void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    // Neu do thi co huong thi bo v -> u
}


void DFS_list(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        cout << u << " "; // xu ly u

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}


void BFS_list(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " "; // xu ly u

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    // danh sach ke: graph[u] luu cac dinh ke voi u
    vector<vector<int>> graph(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // neu la do thi vo huong
    }

    int start;
    cin >> start;

    cout << "DFS: ";
    DFS_list(start, graph);
    cout << "\n";

    cout << "BFS: ";
    BFS_list(start, graph);
    cout << "\n";

    return 0;
}