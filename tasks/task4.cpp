#include <iostream>
using namespace std;

const int INF = 2e9;

void solveTask4(int n) {
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

int main() {
    int n;
    cin >> n;
    solveTask4(n);
    return 0;
}
