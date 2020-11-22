#include <stdio.h>
#include <string.h>
using namespace std;

const int INF = 2e9;

bool is_palindrome(char t[20], int i) {
    if (i == (strlen(t) - 1) / 2)
        return true;
    else if (t[i] == t[strlen(t) - i - 2])
        is_palindrome(t, i + 1);
    else
        return false;
}

int main() {
    char t[20];
    fgets(t, 20, stdin);
    printf("%s", (is_palindrome(t, 0) == true ? "Palindrome" : "Not a palindrome"));
    return 0;
}
