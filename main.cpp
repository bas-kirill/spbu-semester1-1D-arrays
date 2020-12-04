#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int INF = 2e9;
const int MAXN = 10'000;

int solveTask1Array(int n, int m) {
    double** arr;
    arr = new double* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new double[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    int* a = new int[n * m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i * m + j] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << "  ";
        cout << endl;
    }

    for (int i = 0; i < n * m; i++) {
        cout << a[i] << "   ";
    }
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
        x = y;
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
        mx = max(mx, n - start);

    cout << mx;
}

void solveTask3(int n) {
    int a[n];
    cout << "Input array elements: ";
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    
    int copyN = n;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j]) {
              for (int k = j; k < n ; ++k) 
                 a[k] = a[k + 1];
              a[n - 1] = 0;
              --n, --j; 
            }
        }
    }
    
    for (int i = 0; i < copyN; ++i)
        cout << a[i] << " ";
}

void solveTask4Linear(int n) {
    int mx1 = -INF, mx2 = -INF; // mx1 >= mx2
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x >= mx1) {
            mx2 = mx1;
            mx1 = x;
        } else if (x > mx2) {
            mx2 = x;
        }
    }

    cout << mx1 << ' ' << mx2;
}

void solveTask4Array(int n) {
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx1 = -INF, mx2 = -INF; // mx1 >= mx2
    for (int i = 0; i < n; ++i) {
        int x = a[i];

        if (x >= mx1) {
            mx2 = mx1;
            mx1 = x;
        } else if (x > mx2) {
            mx2 = x;
        }
    }

    cout << mx1 << ' ' << mx2;
}

int* merge(int a[], int m, int b[], int n) {
    int *c = new int[n + m];
    int i = 0, j = 0;
    int idx = 0;
    while (i < m || j < n) {
        if (j == n || (i < m && a[i] < b[j]))
            c[idx++] = a[i++];
        else
            c[idx++] = b[j++];
    }

    return c;
}

int binSearchRecursive(int a[], int l, int r, int x) {
    if (l + 1 >= r)
        return l;

    int m = l + (r - l) / 2;
    if (x <= a[m])
        binSearchRecursive(a, l, m, x);
    else if (x > a[m])
        binSearchRecursive(a, m, r, x);
}

void solveTask5(int n) {
    cout << "Input array elements: ";
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int x;
    cout << "Input x: ";
    cin >> x;
    int idx = binSearchRecursive(a, 0, n + 1, x);
    if (idx + 1 < n && a[idx + 1] == x) {
        cout << "Found: " << idx + 1 << endl;
    } else {
        cout << "Not found" << endl;
    }
}

void solveTask6(int m, int n) {
    int a[MAXN], b[MAXN];
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int *c = merge(a, m, b, n);

    for (int i = 0; i < m + n; ++i)
        cout << c[i] << ' ';
}

bool is_palindrome(char t[MAXN], int i) {
    if (i == (strlen(t) - 1) / 2)
        return true;
    else if (t[i] == t[strlen(t) - i - 1])
        is_palindrome(t, i + 1);
    else
        return false;
}

void solveTask7(char t[]) {
    char tWithoutSeparators[MAXN];
    memset(tWithoutSeparators, '\0', MAXN);
    int idx = 0;
    for (int i = 0; i < strlen(t); ++i) {
        if (t[i] != ' ')
            tWithoutSeparators[idx++] = t[i];
    }

    int lastIdx = strlen(tWithoutSeparators) - 1;
    if (tWithoutSeparators[lastIdx] == '\n')
        tWithoutSeparators[lastIdx] = '\0';
    cout << lastIdx << endl;
    printf("%s", (is_palindrome(tWithoutSeparators, 0) ? "Palindrome" : "Not a palindrome"));
}

int main() {
    int n, m;
    int i = 1;
    while (i) {
        cin >> i;
        switch (i) {
            case 1:
                cout << "Input number: ";
                cin >> n >> m;
                solveTask1Array(n, m);
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
                solveTask4Array(n);
                cout << endl;
                break;
            case 5:
                int n;
                cout << "Input array size: ";
                cin >> n;
                solveTask5(n);
                break;
            case 6:
                cout << "Input numbers: ";
                cin >> m >> n;
                solveTask6(m, n);
                cout << endl;
                break;
            case 7:
                char t[MAXN];
                cout << "Input string: ";
                solveTask7(t);
                cout << endl;
                break;
        }
    }
    return 0;
}
