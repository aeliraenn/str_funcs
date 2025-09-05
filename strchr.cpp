#include <stdio.h>
#include <assert.h>

const char* my_strchr (const char *s, int ch)  {
    assert(s);
    int c = 0;
    while ((c = *s) && (c != ch)) {
        s++;
    }
    if (c == ch) {
        return s;
    }
    else {
        return NULL;
    }
}

int main () {
    const char s[] = "ABACABA";
    printf("%c", *my_strchr(s, 'A'));
    return 0;
}
