#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Error use after free fd
int main() {
	char *s = malloc(1);
	free(s);
	printf("%s", s);
	return (0);
}
