#include <stdio.h>
#include <assert.h>

char* my_fgets (char *s, int n, FILE *f) {
    assert(s);
    assert(f);

    char c = 0;
    char *ps = s;
    while ((--n > 0) && (c = getc(f)) != EOF) {
        if ((*ps++ = c) == '\n') {
            break;
        }
    }
    *ps = '\0';
    return (c == EOF && ps == s) ? NULL : s;
}

int main () {
    FILE *f = fopen("file.txt", "r");
    char s[15] = "";
    my_fgets(s, 10, f);
    printf("%s", s);

    return 0;
}
