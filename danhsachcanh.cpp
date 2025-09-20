#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Mở file vào/ra (nếu muốn đọc từ bàn phím thì bỏ 2 dòng freopen)
    freopen("danhsachcanh.inp", "r", stdin);
    freopen("DanhSachCanh.out", "w", stdout);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> deg(n + 1, 0);  // mảng bậc của đỉnh

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        cout << deg[i] << '\n';
    }

    return 0;
}
