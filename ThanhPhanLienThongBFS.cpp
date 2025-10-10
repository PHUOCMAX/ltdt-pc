#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("ThanhPhanLienThongBFS.inp");
    ofstream fout("ThanhPhanLienThongBFS.out");

    int n;
    fin >> n;
    fin.ignore(); // bỏ ký tự xuống dòng còn lại sau số n

    vector<vector<int>> adj(n + 1);

    // đọc danh sách kề
    for (int i = 1; i <= n; i++) {
        string line;
        if (!getline(fin, line)) continue;
        stringstream ss(line);
        int v;
        while (ss >> v) {
            adj[i].push_back(v);
        }
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> components;

    // BFS từng thành phần
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> comp;
            queue<int> q;
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                comp.push_back(u);

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            sort(comp.begin(), comp.end());
            components.push_back(comp);
        }
    }

    fout << components.size() << "\n";
    for (auto &comp : components) {
        for (int v : comp) fout << v << " ";
        fout << "\n";
    }

    return 0;
}
