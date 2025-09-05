#include <stdio.h>
#include <assert.h>


char* my_strncat(char *dest, const char *src, int n) {
    assert(dest);
    assert(src);

    char *pdest = dest;
    int i = 0;
    while (dest[i]) {
        i++;
    }
    int copied = 0;
    while ((++copied <= n) && (dest[i++] = *src++));
    return pdest;
}

int main () {
    char s1[10] = "ABA";
    //s1[0] = 'A';
    //s1[1] = 'B';
    //s1[2] = 'A';
    const char s2[] = "CABA";
    my_strncat(s1, s2, 2);
    for (int i = 0; s1[i] != '\0'; i++) {
        putchar(s1[i]);
        putchar(i);
    }

    return 0;
}

