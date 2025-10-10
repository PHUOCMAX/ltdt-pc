#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // Khoảng cách từ i -> i = 0
    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    // Nhập dữ liệu đồ thị vô hướng
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w); // phòng trường hợp nhiều cạnh
        dist[v][u] = min(dist[v][u], w);
    }

    // Thuật toán Floyd–Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // In kết quả
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << "INF";
            else cout << dist[i][j];
            if (j < n) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
