ASAN= -fsanitize=address -fsanitize-recover=address
#-fsanitize-address-use-after-scope 
all:
	cc -w $(ASAN) main.c -o Pride.error -no-pie
test:
	cc -w $(ASAN) test.c -o test -no-pie
pa:
	cc -w $(ASAN) pa.c -o PartiallyAddressable.error -no-pie
fd:
	cc -w $(ASAN) fd.c -o Pridefd.error -no-pie
fa:
	cc -w $(ASAN) fa.c -o Pridefa.error -no-pie
poison:
	cc -w $(ASAN) poison.c -o Poison.error -no-pie
