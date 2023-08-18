#include <stdio.h>
#include <stdlib.h>

#define BUG_FIX *a +=

int main() {
    char *a = (char *)malloc(sizeof(char) * 10);
    strcpy(a, "asdfg");
    free(a);
    BUG_FIX 1;
    return 0;
}