#include <iostream>
using namespace std;

const int INF = 2e9;

int main() {
    int m, n;
    cin >> m >> n;

    int a[m], b[n];
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int c[m + n];
    for (int i = 0; i < m + n; ++i) {
        if (i < m)
            c[i] = a[i];
        else
            c[i] = b[i - m];
    }

    for (int i = 0; i < m + n; ++i)
        cout << c[i] << ' ';

    return 0;
}
