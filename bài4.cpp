#include <iostream>
using namespace std;

long long countTrailingZeros(long long N) {
    long long res = 0;
    while (N > 0) {
        N /= 5;
        res += N;
    }
    return res;
}

int main() {
    long long N;
    while (cin >> N) {
        cout << countTrailingZeros(N) << "\n";
    }
    return 0;
}
