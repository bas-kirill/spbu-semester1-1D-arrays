#include <stdio.h>
#include <string.h>
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

void solveTask3(int n) {
    int idx = 0;
    int a[n];
    for (int i = 0; i < n; ++i) a[i] = INF;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (a[idx] != x) {
            if (i == 0) {
                a[idx] = x;
            } else {
                a[++idx] = x;
            }
        }
    }

    for (int i = 0; i < idx + 1; ++i)
        cout << a[i] << " ";
}

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

int* merge(int a[], int m, int b[], int n) {
    int c[2 * MAXN];
    for (int i = 0; i < m + n; ++i) {
        if (i < m)
            c[i] = a[i];
        else
            c[i] = b[i - m];
    }

    return c;
}

void solveTask6(int m, int n) {
    int a[MAXN], b[MAXN];
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

bool is_palindrome(char t[MAXN], int i) {
    if (i == (strlen(t) - 1) / 2)
        return true;
    else if (t[i] == t[strlen(t) - i - 2])
        is_palindrome(t, i + 1);
    else
        return false;
}

void solveTask7(char t[]) {
    char tWithoutSeparators[MAXN];
    int idx = 0;
    for (int i = 0; i < strlen(t); ++i) {
        if (t[i] != ' ' )
            tWithoutSeparators[idx++] = t[i];
    }

    int lastIdx = strlen(tWithoutSeparators);
    if (tWithoutSeparators[lastIdx] == '\n')
        tWithoutSeparators[lastIdx] = '\0';

    printf("%s", (is_palindrome(tWithoutSeparators, 0) ? "Palindrome" : "Not a palindrome"));
}

int main() {
    int taskNumber = 7;
    int n, m;
    switch (taskNumber) {
        case 1:
            cout << "Input number: ";
            cin >> n;
            solveTask1Array(n);
            cout << endl;
            break;
        case 2:
            cout << "Input number: ";
            cin >> n;
            solveTask2Array(n);
            cout << endl;
            break;
        case 3:
            cout << "Input number: ";
            cin >> n;
            solveTask3(n);
            cout << endl;
            break;
        case 4:
            cout << "Input number: ";
            cin >> n;
            solveTask4(n);
            cout << endl;
            break;
        case 6:
            cout << "Input numbers: ";
            cin >> m >> n;
            solveTask6(m, n);
            cout << endl;
        case 7:
            char t[MAXN];
            cout << "Input string: ";
            fgets(t, MAXN, stdin);
            solveTask7(t);
            cout << endl;
            break;
    }
    return 0;
}
