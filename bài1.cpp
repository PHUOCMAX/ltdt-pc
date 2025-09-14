#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();

        unordered_map<string, int> freq;
        int max_count = 0;

        for (int i = 0; i + 2 < n; i++) {
            string tri = s.substr(i, 3);
            int cnt = ++freq[tri];
            if (cnt > max_count) {
                max_count = cnt;
            }
        }

        cout << max_count << "\n";
    }
    return 0;
}
