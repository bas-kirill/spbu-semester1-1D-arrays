#include <iostream>
using namespace std;

const int INF = 2e9;

int main() {
    int n;
    cin >> n;
    int idx = 0, cnt = 0;
    int a[n];
    for (int i = 0; i < n; ++i) a[i] = INF;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (a[idx] != x) {
            a[++idx] = x;
            ++cnt;
        }
    }

    for (int i = 0; i < idx; ++i)
        cout << a[i];

    return 0;
}
