#include <stdio.h>
#include <assert.h>


char * my_strncpy (char *dest, const char *source, int n) {
    assert(dest);
    assert(source);

    int copied = 0;
    char *pdest = dest;
    while ((copied++ < n) && (*dest++ = *source++));
    if (copied <= n) {
        *dest = '\0';
    }
    return pdest;
}

int main () {
    const char s1[] = "ABACABA";
    char s2[100] = "";
    my_strncpy(s2, s1, 4);
    printf("%s", s2);

    return 0;
}
