# Pride-Memory-Sin
I want to make a pride flag with fsanitize errors.

## Todo
- [ ]Addressable 00
- [ ]Partially addressable | 01
- [ ]Partially addressable | 02
- [ ]Partially addressable | 03
- [ ]Partially addressable | 04
- [ ]Partially addressable | 05
- [ ]Partially addressable | 06
- [ ]Partially addressable | 07
- [ ]Heap left redzone | fa
- [ ]Freed heap region | fd
- [ ]Stack left redzone | f1
- [ ]Stack mid redzone | f2
- [ ]Stack right redzone | f3
- [ ]Stack after return | f5
- [ ]Stack use after scope | f8
- [ ]Global redzone | f9
- [ ]Global init order | f6
- [ ]Poisoned by user | f7
- [ ]Container overflow | fc
- [ ]Array cookie | ac
- [ ]Intra object redzone | bb
- [ ]ASan internal | fe
- [ ]Left alloca redzone | ca
- [ ]Right alloca redzone | cb
- [ ]Shadow gap | cc


## Fuentes

- [Microsoft](https://devblogs.microsoft.com/cppblog/addresssanitizer-continue_on_error/)
- [Google](https://github.com/google/sanitizers/wiki/AddressSanitizer)
- [Stackoverflow](https://stackoverflow.com/questions/22696071/how-to-make-addresssanitizer-not-stop-after-one-error-and-other-issues)
- [github](https://github.com/google/sanitizers/wiki/AddressSanitizerFlags/81126965c19a22c0dff2ebe242a12b7a6e26b37c)
- [llvm](https://github.com/llvm/llvm-project/blob/main/compiler-rt/lib/asan/asan_mapping.h)
- [Stacko](https://stackoverflow.com/questions/76303855/asan-stack-use-after-return-want-to-learn-more-about-the-shadow-bytes-around)
- [Micro](https://learn.microsoft.com/en-us/cpp/sanitizers/error-stack-use-after-return?view=msvc-170)
