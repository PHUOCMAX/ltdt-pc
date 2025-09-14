#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int nx, ny, nz;
    cin >> nx;
    set<int> sx, sy, sz;

    for (int i = 0; i < nx; i++) {
        int val;
        cin >> val;
        sx.insert(val);
    }

    cin >> ny;
    for (int i = 0; i < ny; i++) {
        int val;
        cin >> val;
        sy.insert(val);
    }

    cin >> nz;
    for (int i = 0; i < nz; i++) {
        int val;
        cin >> val;
        sz.insert(val);
    }

    // Tìm giao của 3 tập
    vector<int> tmp, result;

    // giao sx và sy
    set_intersection(sx.begin(), sx.end(), sy.begin(), sy.end(), back_inserter(tmp));
    // giao với sz
    set_intersection(tmp.begin(), tmp.end(), sz.begin(), sz.end(), back_inserter(result));

    cout << result.size() << "\n";
    for (size_t i = 0; i < result.size(); i++) {
        if (i) cout << " ";
        cout << result[i];
    }
    cout << "\n";

    return 0;
}
