#include <iostream>
using namespace std;

const int INF = 2e9;

void solveTask4Linear(int n) {
    int mx1 = -INF, mx2 = -INF; // mx1 >= mx2
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x > mx1) {
            mx2 = mx1;
            mx1 = x;
        } else if (x > mx2) {
            mx2 = x;
        }
    }

    cout << mx1 << ' ' << mx2;
}

void solveTask4Array(int n) {
    int *a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int mx1 = -INF, mx2 = -INF; // mx1 >= mx2
    for (int i = 0; i < n; ++i) {
        int x = a[i];

        if (x > mx1) {
            mx2 = mx1;
            mx1 = x;
        } else if (x > mx2) {
            mx2 = x;
        }
    }

    cout << mx1 << ' ' << mx2;
}

int main() {
    int n;
    cin >> n;
    solveTask4Array(n);
    return 0;
}
