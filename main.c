#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int *ptr; // global definition
// stack allocate and initialize`ptr` 
void alloc() {
  int local[10];
  ptr = &local[0];
}
// make a `return`
int ret_after_use() {
    return ptr[10];
}
int main() {
	/*
	char *s;
	s = (char *)malloc(20);
	s = "1";
	free(s);*/

	//free((void *)1);
	/*	
	alloc();
	int i = ret_after_use();
	ptr = &i; // error: use after return
	*/

	
	char *s = malloc(1);
	free(s);
	printf("%s", s);//error: use after free
	
	/*
	int *pride;
	{
	pride = (int *)malloc(1);
	}
	*/
	//int *i = (int *)malloc(1);
return (0);
}
