#include <iostream>
using namespace std;

const int INF = 2e9;
const int MAXN = 10'000;

int solveTask1Array(int n) {
    int a[MAXN];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cnt = 1;
    int x = a[0];
    for (int i = 1; i < n; ++i) {
        int y = a[i];
        if (x != y)
            ++cnt;
        y = x;
    }

    cout << cnt;
}

void solveTask1Linear(int n) {
    int cnt = 1;
    int x;
    cin >> x;
    for (int i = 1; i < n; ++i) {
        int y;
        cin >> y;
        if (x != y)
            ++cnt;
        y = x;
    }

    cout << cnt;
}

int main() {
    int n;
    cin >> n;
    solveTask1Array(n);
    return 0;
}
