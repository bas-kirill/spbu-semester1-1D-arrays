#include <iostream>
using namespace std;

const int INF = 2e9;

int main() {
    int n;
    cin >> n;

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

    return 0;
}
