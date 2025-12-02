#include <stdio.h>

//Hace heap overflow del numero que digas
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: ./PartiallyAddressable [number of bytes overflow]\n");
		return (0);
	}
	int numbytes = atoi(argv[1]);
	numbytes %= 8;
	char *str = (char *)malloc(numbytes);
	strcpy(str, "Esto siempre sera demasiado largo.\n");
	printf("%s", str);
	free(str);
	return (0);
}
