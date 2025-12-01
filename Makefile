ASAN= -fsanitize=address -fsanitize-recover=address
#-fsanitize-address-use-after-scope 
all:
	cc -w $(ASAN) main.c -o Pride -no-pie
test:
	cc -w $(ASAN) test.c -o test -no-pie
04:
	cc -w $(ASAN) 04.c -o Pride02 -no-pie
02:
	cc -w $(ASAN) 02.c -o Pride02 -no-pie
fd:
	cc -w $(ASAN) fd.c -o Pridefd -no-pie
fa:
	cc -w $(ASAN) fa.c -o Pridefa -no-pie
