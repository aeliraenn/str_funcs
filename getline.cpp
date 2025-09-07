#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

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
    char* str = NULL;
    size_t len = 0;
    my_getline(&str, &len, stdin);
    printf("%s", str);
    free(str);

    return 0;
}
