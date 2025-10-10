#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(n + 1, INF), parent(n + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du != dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[t] == INF) {
        cout << "-1\n"; // không có đường đi
        return 0;
    }

    // Truy vết đường đi ngắn nhất
    vector<int> path;
    for (int cur = t; cur != -1; cur = parent[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << path.size() << " " << dist[t] << "\n";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i + 1 < (int)path.size()) cout << " ";
    }
    cout << "\n";

    return 0;
}
