#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int INF = 2e9;
const int MAXN = 10'000;

bool is_palindrome(char t[MAXN], int i) {
//    cout << i << endl;
    if (i == (strlen(t) - 1) / 2)
        return true;
    else if (t[i] == t[strlen(t) - i - 2])
        is_palindrome(t, i + 1);
    else
        return false;
}

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

void solveTask2(int n) {
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

void solveTask3(int n) {
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

void solveTask6(int m, int n) {
    int a[MAXN], b[MAXN];
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
}

void solveTask7(char t[]) {
    char tWithoutSpaces[MAXN];
    int idx = 0;
    for (int i = 0; i < strlen(t); ++i) {
        if (t[i] != ' ' )
            tWithoutSpaces[idx++] = t[i];
    }

    for (int i = 0; i < strlen(tWithoutSpaces); ++i) {
        if (t[i] == '\n')
            t[i] = '\0';
    }
    printf("%s", (is_palindrome(tWithoutSpaces, 0) ? "Palindrome" : "Not a palindrome"));
}

int main() {
    int n;
    cin >> n;
    solveTask1(n);
    cin >> n;
    solveTask2(n);
    cin >> n;
    solveTask3(n);
    cin >> n;
    solveTask4(n);
    int m;
    cin >> m >> n;
    solveTask6(m, n);
    char t[MAXN];
    fgets(t, MAXN, stdin);
    solveTask7(t);
    return 0;
}
