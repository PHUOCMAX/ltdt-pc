#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#define FI "MATRANKE.INP"
#define FO "matranke.out"

int n;
vector<vector<int>> a;

void solve() {
    // Đọc số đỉnh n từ tệp đầu vào
    cin >> n;

    // Khởi tạo kích thước cho ma trận kề
    a.resize(n, vector<int>(n));

    // Đọc ma trận kề
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    // Ghi số đỉnh ra tệp đầu ra
    cout << n << endl;

    // Tính và in bậc của từng đỉnh
    for(int i = 0; i < n; ++i) {
        int degree = 0;
        for(int j = 0; j < n; ++j) {
            degree += a[i][j];
        }
        cout << degree << endl;
    }
    cout << endl;
}

int main() {
    // Chuyển hướng đầu vào và đầu ra từ tệp
    freopen(FI, "r", stdin);
    freopen(FO, "w", stdout);

    solve();

    return 0;
}