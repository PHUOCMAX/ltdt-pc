#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("LienThongBFS.inp");
    ofstream fout("LienThongBFS.out");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Khong the mo file!\n";
        return 1;
    }

    int n, x;
    if (!(fin >> n >> x)) {
        cerr << "Loi: khong doc duoc n va x\n";
        return 1;
    }

    // Đảm bảo bỏ phần còn lại của dòng chứa n và x (an toàn với CRLF/BOM)
    string line;
    getline(fin, line); // ăn newline sau n x

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; ++i) {
        if (!getline(fin, line)) {
            // Nếu file kết thúc sớm, coi như dòng rỗng
            line = "";
        }
        // Nếu có CR ở cuối (Windows CRLF), loại bỏ
        if (!line.empty() && line.back() == '\r') line.pop_back();

        // Parse các số trong dòng (các đỉnh kề)
        stringstream ss(line);
        int v;
        while (ss >> v) {
            if (v >= 1 && v <= n) adj[i].push_back(v);
            // nếu muốn, có thể else báo lỗi hoặc bỏ qua số không hợp lệ
        }
    }

    // BFS từ x
    vector<bool> visited(n + 1, false);
    queue<int> q;
    vector<int> result;

    if (x >= 1 && x <= n) {
        visited[x] = true;
        q.push(x);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u != x) result.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    } else {
        // x không hợp lệ
    }

    // Ghi kết quả
    fout << result.size() << "\n";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i) fout << " ";
        fout << result[i];
    }
    fout << "\n";

    fin.close();
    fout.close();
    return 0;
}
