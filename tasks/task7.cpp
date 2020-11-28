#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

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
    char t[MAXN];
    fgets(t, MAXN, stdin);
    solveTask7(t);
    return 0;
}
