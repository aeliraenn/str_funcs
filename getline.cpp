#include <assert.h>
#include <stdio.h>


int getline (char *s, int n) {   //n = lim - 1
    int c = 0;
    int i = 0;
    while ((--n > 0) && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int main () {
    char s[10] = "";
    getline(s, 5);
    printf("%s", s);

    return 0;
}
