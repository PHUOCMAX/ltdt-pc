#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<bool> check(N + 1, false);
    bool isPermutation = true;

    for (int x : A) {
        if (x < 1 || x > N) {      // ngoài phạm vi [1..N]
            isPermutation = false;
            break;
        }
        if (check[x]) {            // đã xuất hiện rồi (bị trùng)
            isPermutation = false;
            break;
        }
        check[x] = true;
    }

    if (isPermutation) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
