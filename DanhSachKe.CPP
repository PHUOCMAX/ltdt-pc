#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

#define FI "DanhSachKe.inp"
#define FO "DanhSachKe.out"

int n;
vector<int> degree;

void solve() {
    // đọc số đỉnh
    if (!(cin >> n)) return;
    // bỏ hết ký tự còn lại trên dòng (an toàn với '\n' và '\r\n')
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    degree.assign(n + 1, 0);

    string line;
    for (int i = 1; i <= n; ++i) {
        if (!getline(cin, line)) line = "";   // nếu EOF sớm, coi như rỗng
        // loại bỏ '\r' cuối dòng nếu có (Windows CRLF)
        if (!line.empty() && line.back() == '\r') line.pop_back();

        // nếu dòng rỗng -> đỉnh cô lập (bậc 0)
        if (line.empty()) continue;

        stringstream ss(line);
        int x;
        while (ss >> x) {
            // nếu file dùng '-1' làm sentinel, dừng khi gặp -1
            if (x == -1) break;
            // mỗi số trong dòng được tính 1 đơn vị bậc (theo mẫu bạn mong muốn)
            degree[i]++;
        }
    }

    // in kết quả
    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << degree[i] << '\n';
    }
}

int main() {
    freopen(FI, "r", stdin);
    freopen(FO, "w", stdout);

    solve();
    return 0;
}

