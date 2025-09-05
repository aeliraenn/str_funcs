#include <assert.h>
#include <stdio.h>

char* my_strcpy (char *dest, const char *source) {
    assert(dest);
    assert(source);

    char *pdest = dest;
    while (*dest++ = *source++);
    return pdest;
}

int main () {
    const char s1[] = "ABCDE";
    char s2[10];
    my_strcpy(s2, s1);
    printf("%s", s2);

    return 0;
}
