#include <iostream>
using namespace std;

const int INF = 2e9;

void solveTask2Linear(int n) {
    bool isSeq = false;
    int mx = 0;
    int start = -1, end = -1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x % 2 == 1) {
            if (!isSeq) {
                start = i;
                isSeq = true;
            }
        } else {
            if (isSeq) {
                end = i - 1;
                isSeq = false;
                mx = max(mx, end - start + 1);
            }
        }
    }

    if (start > end)
        mx = max(mx, n - start + 1);

    cout << mx;
}

void solveTask2Array(int n) {
    int *a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool isSeq = false;
    int mx = 0;
    int start = -1, end = -1;
    for (int i = 0; i < n; ++i) {
        int x = a[i];

        if (x % 2 == 1) {
            if (!isSeq) {
                start = i;
                isSeq = true;
            }
        } else {
            if (isSeq) {
                end = i - 1;
                isSeq = false;
                mx = max(mx, end - start + 1);
            }
        }
    }

    if (start > end)
        mx = max(mx, n - start + 1);

    cout << mx;
}

int main() {
    int n;
    cin >> n;
    solveTask2Array(n);
    return 0;
}
