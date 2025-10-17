#include <bits/stdc++.h>
using namespace std;

struct Circle {
    double x, y, r;
};

struct Node {
    int id;
    int jumps; // số lần nhảy
    int steps; // số hình đi qua
    bool operator<(const Node &other) const {
        if (jumps != other.jumps) return jumps > other.jumps;
        return steps > other.steps;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("CIRCLE.INP");
    ofstream fout("CIRCLE.OUT");
    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Không thể mở file.\n";
        return 1;
    }

    int N, S, T;
    fin >> N >> S >> T;
    vector<Circle> a(N + 1);
    for (int i = 1; i <= N; i++) fin >> a[i].x >> a[i].y >> a[i].r;

    vector<vector<pair<int,int>>> adj(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            double d = hypot(a[i].x - a[j].x, a[i].y - a[j].y) - (a[i].r + a[j].r);
            if (d <= 50.0) {
                adj[i].push_back({j, 0});
                adj[j].push_back({i, 0});
            } else if (d <= 60.0) {
                adj[i].push_back({j, 1});
                adj[j].push_back({i, 1});
            }
        }
    }

    const int INF = 1e9;
    vector<int> minJump(N + 1, INF), minStep(N + 1, INF);
    vector<int> prevNode(N + 1, -1), moveType(N + 1, -1);

    priority_queue<Node> pq;
    pq.push({S, 0, 1});
    minJump[S] = 0;
    minStep[S] = 1;

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        if (cur.id == T) break;
        if (cur.jumps > minJump[cur.id] ||
            (cur.jumps == minJump[cur.id] && cur.steps > minStep[cur.id]))
            continue;

        for (auto [v, t] : adj[cur.id]) {
            int newJ = cur.jumps + t;
            int newS = cur.steps + 1;
            if (newJ < minJump[v] || (newJ == minJump[v] && newS < minStep[v])) {
                minJump[v] = newJ;
                minStep[v] = newS;
                prevNode[v] = cur.id;
                moveType[v] = t;
                pq.push({v, newJ, newS});
            }
        }
    }

    if (minJump[T] == INF) {
        fout << 0 << "\n";
        return 0;
    }

    // Truy vết đường đi
    vector<pair<int,int>> path;
    for (int u = T; u != -1; u = prevNode[u])
        path.push_back({u, moveType[u]});
    reverse(path.begin(), path.end());

    fout << 1 << "\n";
    fout << minJump[T] << " " << (int)path.size() - 1 << "\n";
    // Không in hình xuất phát, chỉ in từ hình thứ 2
    for (size_t i = 1; i < path.size(); i++)
        fout << path[i].first << " " << path[i].second << "\n";

    return 0;
}
