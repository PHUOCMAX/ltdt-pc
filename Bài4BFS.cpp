#include <bits/stdc++.h>
using namespace std;

int n, x, y, z;
vector<vector<int>> adj;

// Đếm số thành phần liên thông bằng BFS
int countComponents(int ignoreNode = -1, int u1 = -1, int u2 = -1) {
    vector<bool> visited(n + 1, false)
    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (i == ignoreNode || visited[i]) continue;

        components++;
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                // bỏ cạnh (u1, u2)
                if ((u == u1 && v == u2) || (u == u2 && v == u1)) continue;
                // bỏ đỉnh ignoreNode
                if (v == ignoreNode) continue;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return components;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("CanhCauDinhKhopBFS.inp");
    ofstream fout("CanhCauDinhKhopBFS.out");

    fin >> n >> x >> y >> z;
    fin.ignore(); // bỏ ký tự xuống dòng

    adj.assign(n + 1, {});

    // đọc danh sách kề (mỗi dòng là danh sách của 1 đỉnh)
    for (int i = 1; i <= n; i++) {
        string line;
        if (!getline(fin, line)) continue;
        stringstream ss(line);
        int v;
        while (ss >> v) {
            adj[i].push_back(v);
        }
    }

    // số thành phần ban đầu
    int base = countComponents();

    // kiểm tra cạnh cầu
    int afterRemoveEdge = countComponents(-1, x, y);
    if (afterRemoveEdge > base)
        fout << "canh cau\n";
    else
        fout << "khong la canh cau\n";

    // kiểm tra đỉnh khớp
    int afterRemoveNode = countComponents(z);
    if (afterRemoveNode > base)
        fout << "dinh khop\n";
    else
        fout << "khong la dinh khop\n";

    return 0;
}
