#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Heap overflow num 04
int main(int argc, const char *argv[]) {
    char *s = malloc(12);
    strcpy(s, "Hello world!!!!");
    printf("string is: %s\n", s);
    free(s);
    return 0;
}
