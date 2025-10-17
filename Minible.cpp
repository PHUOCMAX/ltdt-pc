#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int x, y;
    int cost;
    bool operator<(const Cell &other) const {
        return cost > other.cost; // ưu tiên chi phí nhỏ hơn (min-heap)
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("MINTABLE.INP");
    ofstream fout("MINTABLE.OUT");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Không thể mở file.\n";
        return 1;
    }

    int N, M, xi, yi, xj, yj;
    fin >> N >> M >> xi >> yi >> xj >> yj;
    xi--, yi--, xj--, yj--; // đổi sang chỉ số 0-based

    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            fin >> A[i][j];

    // 4 hướng di chuyển
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    vector<vector<int>> dist(N, vector<int>(M, 1e9));
    vector<vector<pair<int,int>>> parent(N, vector<pair<int,int>>(M, {-1,-1}));
    priority_queue<Cell> pq;

    dist[xi][yi] = 0;
    pq.push({xi, yi, 0});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y, c = cur.cost;
        if (c > dist[x][y]) continue;
        if (x == xj && y == yj) break;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (A[nx][ny] == 0) continue;

            // chi phí không tính ô đầu và cuối
            int addCost = ((nx == xj && ny == yj) ? 0 : A[nx][ny]);
            if (dist[nx][ny] > dist[x][y] + addCost) {
                dist[nx][ny] = dist[x][y] + addCost;
                parent[nx][ny] = {x, y};
                pq.push({nx, ny, dist[nx][ny]});
            }
        }
    }

    if (dist[xj][yj] == 1e9) {
        fout << 0 << "\n";
        return 0;
    }

    fout << 1 << "\n";
    fout << dist[xj][yj] << "\n";

    // Truy vết đường đi
    vector<pair<int,int>> path;
    for (int x = xj, y = yj; x != -1 && y != -1; tie(x, y) = parent[x][y])
        path.push_back({x, y});
    reverse(path.begin(), path.end());

    for (auto [x, y] : path)
        fout << x + 1 << " " << y + 1 << "\n";

    return 0;
}
