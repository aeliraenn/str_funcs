#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strdup(const char *str)  {
    assert(str);

    char *ptr = (char *)malloc(strlen(str)+1); // +1 для '\0'
    if (ptr != NULL) {
        strcpy(ptr, str);
    }
    return ptr;
}


int main () {
    const char str[] = "ABACABA";
    printf("%s", my_strdup(str));

    return 0;
}
