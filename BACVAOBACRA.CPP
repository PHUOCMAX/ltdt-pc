#include <iostream>
#include <vector>

using namespace std;

#define FI "BACVAOBACRA.INP"
#define FO "BacVaoBacRa.out"

int n;
vector<vector<int>> a;

void solve() {
    // Đọc số đỉnh
    cin >> n;

    // Khởi tạo ma trận kề
    a.resize(n, vector<int>(n));

    // Đọc ma trận kề
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    // Tính bậc vào và bậc ra
    vector<int> indeg(n, 0), outdeg(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            outdeg[i] += a[i][j]; // bậc ra = tổng hàng i
            indeg[j]  += a[i][j]; // bậc vào = tổng cột j
        }
    }

    // Ghi kết quả
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        cout << indeg[i] << ' ' << outdeg[i] << '\n';
    }
}

int main() {
    // Chuyển hướng I/O
    freopen(FI, "r", stdin);
    freopen(FO, "w", stdout);

    solve();
    return 0;
}
