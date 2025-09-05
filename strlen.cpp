#include <stdio.h>
#include <assert.h>

int my_strlen (const char *s) {
    assert(s);

    int len = 0;
    while (char c = *s++) {
        len++;
    }
    return len;
}

int main () {
    printf("%d", my_strlen("ABACABA"));
}
