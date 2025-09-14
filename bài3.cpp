#include <iostream>
#include <vector>
using namespace std;

// Sinh các số nguyên tố <= n bằng Sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}

// Tính số mũ của p trong N!
int exponentInFactorial(int N, int p) {
    int exp = 0;
    while (N) {
        N /= p;
        exp += N;
    }
    return exp;
}

int main() {
    int N;
    vector<int> primes = sieve(1000); // vì N ≤ 1000
    while (cin >> N) {
        vector<int> exps;
        for (int p : primes) {
            if (p > N) break;
            exps.push_back(exponentInFactorial(N, p));
        }

        // Bỏ các số 0 cuối cùng
        while (!exps.empty() && exps.back() == 0) {
            exps.pop_back();
        }

        // In ra kết quả
        for (size_t i = 0; i < exps.size(); i++) {
            if (i) cout << " ";
            cout << exps[i];
        }
        cout << "\n";
    }
    return 0;
}
