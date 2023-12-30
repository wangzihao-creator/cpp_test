#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n, 0);
    set<int> used;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (used.find(a[i]) == used.end()) {
            b[i] = a[i];
            used.insert(a[i]);
        } else {
            for (int j = 1; j <= n; ++j) {
                if (used.find(j) == used.end()) {
                    b[i] = j;
                    used.insert(j);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }

    return 0;
}
