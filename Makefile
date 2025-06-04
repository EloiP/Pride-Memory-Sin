ASAN= -fsanitize=address -fsanitize-recover=address
#-fsanitize-address-use-after-scope 
all:
	cc -w $(ASAN) main.c -o Pride
