ASAN= -fsanitize=address -fsanitize-recover=address
#-fsanitize-address-use-after-scope 
all:
	cc -w $(ASAN) main2.c -o Pride -no-pie
