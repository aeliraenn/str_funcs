#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char* my_strncpy (char *dest, const char *source, int n) {
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

char* my_strncpy1 (char *dest, const char *source, int n) {
    assert(dest);
    assert(source);

    int copied = 0;
    char *pdest = dest;

    int i = 0;
    while ((copied < n) && (source[i] != '\0')) {
        dest[i] = source[i];
        i++;
        copied++;
    }

    if (copied <= n) {
        *dest = '\0';
    }

    return pdest;
}
            //  указательная арифметика + вынести все из цикла +
// сделать все функции во втором экзмепляре без указательной арифметики
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

char* my_strncat1 (char *dest, const char *src, int n) {
    assert(dest);
    assert(src);

    char *pdest = dest;
    int i = 0;
    while (dest[i]) {
        i++;
    }

    int copied = 0;
    while ((copied < n) && (src[i] != '\0')) {
        dest[i] = src[i];
        copied++;
        i++;
    }
    return pdest;
}

int my_strlen (const char *s) {
    assert(s);

    int len = 0;
    char c = 0;
    while (c = *s++) {
        len++;
    }
    return len;
}

int my_strlen1 (const char *s) {
    assert(s);

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char* my_strcpy (char *dest, const char *source) {
    assert(dest);
    assert(source);

    char *pdest = dest;
    while (*dest++ = *source++);
    return pdest;
}

char* my_strcpy1 (char *dest, const char *source) {
    assert(dest);
    assert(source);

    char *pdest = dest;

    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    return pdest;
}

char* my_strdup(const char *str)  {
    assert(str);

    char *ptr = (char *)calloc(my_strlen(str)+1, sizeof(char)); // +1 для '\0'   , calloc
    if (ptr != NULL) {
        my_strcpy(ptr, str);
    }
    return ptr;
}

char* my_strdup1(const char *str)  {
    assert(str);

    char *ptr = (char *)calloc(my_strlen(str)+1, sizeof(char)); // +1 для '\0'   , calloc
    if (ptr != NULL) {
        my_strcpy(ptr, str);
    }
    return ptr;
}

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

const char* my_strchr1 (const char *s, int ch)  {
    assert(s);

    int i = 0;
    while (s[i] != ch) {
        i++;
    }

    if (s[i] == ch) {
        return s;
    }
    else {
        return NULL;
    }
}

char* my_strcat(char *dest, const char *src) {
    assert(dest);
    assert(src);

    char *pdest = dest;

    while (*dest++);  //finds the end of the destination string

    while (*dest++ = *src++); //copies source string to the end of dest string

    return pdest;
}

char* my_strcat1 (char *dest, const char *src) {
    assert(dest);
    assert(src);

    char *pdest = dest;
    int i = 0;

    while (dest[i] != '\0') {
        i++;
    }

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    return pdest;
}

int my_puts (char *s) {
    assert(s);

    int c = 0;

    while (c = *s++) {
        putchar(c);
    }

    return ferror(stdout) ? EOF : 0;
}

int my_puts1 (char *s) {
    assert(s);

    int i = 0;

    while (s[i] != '\0') {
        putchar(s[i]);
    }

    return ferror(stdout) ? EOF : 0;
}

int my_atoi (const char* s) { // указательная арифметика
    assert(s);

    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <='9'; i++) {
        n = 10*n + (s[i]-'0');
    }
    return n;
}

int my_atoi1 (const char* s) { // указательная арифметика
    assert(s);

    int n = 0;

    while (*s >= '0' && *s <= '9') {   // while (*s >= '0' && *s++ <= '9'); will work??
        n = 10 * n + (*s - '0');
        s++;
    }
    return n;
}

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

char* my_fgets1 (char *s, int n, FILE *f) {
    assert(s);
    assert(f);

    char c = getc(f);
    char *ps = s;

    while ((n >= 0) && (c != EOF)) {
        *ps = c;
        if (*ps == '\n') {
            ps++;
            break;
        }
        n--;
        ps++;
    }

    *ps = '\0';

    return (c == EOF && ps == s) ? NULL : s;
}

ssize_t my_getline (char **lineptr, size_t *len, FILE *stream) {
    assert(lineptr);
    assert(len);
    assert(stream);

    if (*lineptr == NULL || *len == 0) {
        *len = 100;  // initial buffer size if no buffer is provided
        *lineptr = (char *)calloc(*len, sizeof(char));
        if (*lineptr == NULL) {
            perror("Error: calloc couldn\'t allocate space\n");
            return -1;
        }
    }

    size_t pos = 0;
    int c = 0;

    while ((c = fgetc(stream)) != EOF) {
        if (pos + 1 >= *len) { //checks if we need to resize the buffer
            size_t new_size = 2 * (*len);
            char *new_ptr = (char *)realloc(*lineptr, new_size);
            if (new_ptr == NULL) {
                perror("Error: realloc couldn\'t allocate space\n");
                return -1;
            }
            *lineptr = new_ptr;
            *len = new_size;
        }

        (*lineptr)[pos++] = (char)c;

        if (c == '\n') {
            break;
        }
    }

    if (pos < *len) {              //adds '\0' to the end of the string
        (*lineptr)[pos] = '\0';
    } else {            //resizes line for '\0' if needed
        size_t new_size = *len + 1;
        char *new_ptr = (char *)realloc(*lineptr, new_size);
        if (new_ptr == NULL) {
            perror("Error: realloc coldn\'t allocate space\n");
            return -1;
        }
        *lineptr = new_ptr;
        *len = new_size;
        (*lineptr)[pos] = '\0';
    }

    if (pos == 0 && c == EOF) {
        return -1;
    }

    return (ssize_t)pos;
}

int main () {
    FILE *f = fopen("file.txt", "r");
    char s[15] = "";
    my_fgets(s, 10, f);


    return 0;
}
