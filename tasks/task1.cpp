#include <iostream>
using namespace std;

const int INF = 2e9;

void solveTask1(int n) {
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
    solveTask1(n);
    return 0;
}
