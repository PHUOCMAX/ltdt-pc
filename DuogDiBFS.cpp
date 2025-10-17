#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("DuongDiBFS.inp");
    ofstream fout("DuongDiBFS.out");

    int n, x, y;
    fin >> n >> x >> y;

    vector<vector<int>> adj(n + 1);

    // đọc danh sách kề
    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            fin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    queue<int> q;
    visited[x] = true;
    q.push(x);

    // BFS
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // khôi phục đường đi từ y về x
    if (!visited[y]) {
        fout << "0\n"; // không có đường đi
        return 0;
    }

    vector<int> path;
    for (int v = y; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    fout << path.size() << "\n";
    for (int v : path) fout << v << " ";
    fout << "\n";

    return 0;
}
