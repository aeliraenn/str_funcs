#include <stdio.h>
#include <assert.h>


int atoi (const char* s) {
    assert(s);

    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <='9'; i++) {
        n = 10*n + (s[i]-'0');
    }
    return n;
}

int main () {
    const char str[] = "1234";
    int n = 0;
    n = atoi(str);
    printf("%d", n);

    return 0;
}
