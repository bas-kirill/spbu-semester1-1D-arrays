#include <iostream>
using namespace std;

const int INF = 2e9;
const int MAXM = 10'000;

int* merge(int a[], int m, int b[], int n) {
    int c[2 * MAXM];
    for (int i = 0; i < m + n; ++i) {
        if (i < m)
            c[i] = a[i];
        else
            c[i] = b[i - m];
    }

    return c;
}

void solveTask6(int m, int n) {
    int a[MAXM], b[MAXM];
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int *c = merge(a, m, b, n);
    for (int i = 0; i < m + n; ++i) {
        if (i < m)
            c[i] = a[i];
        else
            c[i] = b[i - m];
    }

    for (int i = 0; i < m + n; ++i)
        cout << c[i] << ' ';
}

int main() {
    int m, n;
    cin >> m >> n;
    solveTask6(m, n);
    return 0;
}
