#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct DijkstraResult {
    vector<int> dist;
    vector<int> parent;
};

DijkstraResult dijkstra(int n, int start, const vector<vector<pair<int,int>>>& adj) {
    vector<int> dist(n + 1, INF), parent(n + 1, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

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
    return {dist, parent};
}

vector<int> tracePath(int s, int t, const vector<int>& parent) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    if (path.front() != s) return {}; // không có đường đi
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t, x;
    cin >> n >> m >> s >> t >> x;

    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Dijkstra từ s
    auto res1 = dijkstra(n, s, adj);
    // Dijkstra từ x
    auto res2 = dijkstra(n, x, adj);

    if (res1.dist[x] == INF || res2.dist[t] == INF) {
        cout << "-1\n"; // không có đường đi
        return 0;
    }

    int totalDist = res1.dist[x] + res2.dist[t];

    // Truy vết đường đi s -> x
    vector<int> path1 = tracePath(s, x, res1.parent);
    // Truy vết đường đi x -> t (bỏ đỉnh x đầu để tránh lặp)
    vector<int> path2 = tracePath(x, t, res2.parent);
    path2.erase(path2.begin());

    // Ghép lại
    vector<int> fullPath = path1;
    fullPath.insert(fullPath.end(), path2.begin(), path2.end());

    cout << fullPath.size() << " " << totalDist << "\n";
    for (int i = 0; i < (int)fullPath.size(); i++) {
        cout << fullPath[i];
        if (i + 1 < (int)fullPath.size()) cout << " ";
    }
    cout << "\n";

    return 0;
}
