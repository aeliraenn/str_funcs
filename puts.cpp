#include <stdio.h>
#include <assert.h>

int my_puts (char *s) {
    assert(s);
    int c = 0;
    while (c = *s++) {
        putchar(c);
    }
    return ferror(stdout) ? EOF : 0;
}

int main () {
    char s[] = "ABC";
    my_puts(s);
    return 0;
}
