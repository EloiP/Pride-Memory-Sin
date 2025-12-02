# Pride-Memory-Sin
I want to make a pride flag with fsanitize errors.

## Todo
- [ ] Addressable | 00
- [x] Partially addressable | 01
- [x] Partially addressable | 02
- [x] Partially addressable | 03
- [x] Partially addressable | 04
- [x] Partially addressable | 05
- [x] Partially addressable | 06
- [x] Partially addressable | 07
- [ ] Heap left redzone | fa
- [x] Freed heap region | fd
- [ ] Stack left redzone | f1
- [ ] Stack mid redzone | f2
- [ ] Stack right redzone | f3
- [ ] Stack after return | f5
- [ ] Stack use after scope | f8
- [ ] Global redzone | f9
- [ ] Global init order | f6
- [ ] Poisoned by user | f7
- [ ] Container overflow | fc
- [ ] Array cookie | ac
- [ ] Intra object redzone | bb
- [ ] ASan internal | fe
- [ ] Left alloca redzone | ca
- [ ] Right alloca redzone | cb
- [ ] Shadow gap | cc

## Explicado
- Partially addressable: haces malloc de x y despues intentas iniciarlo con x+n bytes. Lo que provoca que intentes usar memoria no disponible haciendo overflow y intentando acceder mas alla de la estructura asignada. El numero del 00-07 indica cuantos bytes son validos, si los 8 bytes son validos entonces es 00.
## Fuentes

- [Principal](https://learn.microsoft.com/es-es/cpp/sanitizers/asan-error-examples?view=msvc-170)

- [Microsoft](https://devblogs.microsoft.com/cppblog/addresssanitizer-continue_on_error/)
- [Google](https://github.com/google/sanitizers/wiki/AddressSanitizer)
- [Stackoverflow](https://stackoverflow.com/questions/22696071/how-to-make-addresssanitizer-not-stop-after-one-error-and-other-issues)
- [Github](https://github.com/google/sanitizers/wiki/AddressSanitizerFlags/81126965c19a22c0dff2ebe242a12b7a6e26b37c)
- [Llvm](https://github.com/llvm/llvm-project/blob/main/compiler-rt/lib/asan/asan_mapping.h)
- [Stacko](https://stackoverflow.com/questions/76303855/asan-stack-use-after-return-want-to-learn-more-about-the-shadow-bytes-around)
- [Micro](https://learn.microsoft.com/en-us/cpp/sanitizers/error-stack-use-after-return?view=msvc-170)
