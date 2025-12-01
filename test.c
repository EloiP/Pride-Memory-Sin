int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	int numbytes = atoi(argv[1]);
	numbytes %= 8;
	char *str = (char *)malloc(numbytes);
	str = "Esto siempre sera demasiado largo.                                                                                                                                                                                                                                                                                                  \n";
	free(str);
	return (0);
}
