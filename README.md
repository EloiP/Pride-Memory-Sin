# Pride-Memory-Sin
I want to make a pride flag with fsanitize errors.

## Todo
- [ ] Addressable | 00
- [ ] Partially addressable | 01
- [x] Partially addressable | 02
- [ ] Partially addressable | 03
- [x] Partially addressable | 04
- [ ] Partially addressable | 05
- [ ] Partially addressable | 06
- [ ] Partially addressable | 07
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
- 04: haces malloc de x y despues intentas iniciarlo con x+n bytes.
Valor de Shadow Byte

Estado

Descripción

Diferencias Clave en Detección de Errores

Ejemplo en Heap Overflow

00 (0)

Fully addressable

Todos los 8 bytes de la palabra son válidos para acceso.

No hay restricción: cualquier acceso dentro de la palabra es permitido.<br>- ASAN no reporta errores aquí a menos que sea un acceso completamente fuera de bounds (e.g., más allá de la estructura asignada).<br>- Usado para memoria completamente válida (e.g., buffers enteros).
En un heap buffer de 8 bytes, puedes acceder a todos sin error. Si overflows más allá, ASAN detecta "heap-buffer-overflow".

01 (1)

Partially addressable

Solo el primer byte de la palabra es válido.

Acceso a bytes 2-8 causa error inmediato.<br>- Diferencia con 0: Restringe accesos a subconjuntos pequeños; útil para estructuras con padding o campos pequeños.<br>- Más estricto que 0, pero permite accesos mínimos.
En un struct con un char (1 byte) seguido de padding, acceder al padding (byte 2+) aborta con "out-of-bounds access".

02 (2)

Partially addressable

Solo los primeros 2 bytes son válidos.

Similar a 1, pero permite 1 byte más.<br>- Diferencia con 1: Mayor tolerancia para campos de 2 bytes (e.g., short int).<br>- Menos estricto que 1, pero aún detecta overflows en bytes 3+.
Acceso a byte 3+ en un buffer de 2 bytes válidos causa error.

03 (3)

Partially addressable

Solo los primeros 3 bytes son válidos.

Extiende la validez a 3 bytes.<br>- Diferencia con 2: Útil para tipos de 3 bytes (raros, como algunos formatos de datos).<br>- Detecta accesos a bytes 4+ con precisión.
En un array de chars de 3 elementos, overflow a 4+ aborta.

04 (4)

Partially addressable

Solo los primeros 4 bytes son válidos.

Mitad de la palabra (32 bits en 64-bit).<br>- Diferencia con 3: Permite accesos a int de 32 bits.<br>- Común en structs con int + padding.
Acceso a bytes 5+ en un int (4 bytes) causa "heap-buffer-overflow".

05 (5)

Partially addressable

Solo los primeros 5 bytes son válidos.

Extiende a 5 bytes.<br>- Diferencia con 4: Mayor flexibilidad para datos no alineados.<br>- Detecta overflows en bytes 6+.
Útil para buffers de 5 bytes, como strings cortas.

06 (6)

Partially addressable

Solo los primeros 6 bytes son válidos.

Casi toda la palabra, salvo 2 bytes.<br>- Diferencia con 5: Permite más accesos, pero aún estricto.<br>- Raro, pero usado en optimizaciones de memoria.
Acceso a byte 7+ aborta.

07 (7)

Partially addressable

Solo los primeros 7 bytes son válidos.

Casi fully addressable, solo 1 byte restringido.<br>- Diferencia con 6: Muy permisivo, pero detecta el último byte.<br>- Útil para structs con un byte de padding al final.
En un buffer de 7 bytes, acceder al 8vo causa error inmediato.
## Fuentes

- [Principal](https://learn.microsoft.com/es-es/cpp/sanitizers/asan-error-examples?view=msvc-170)

- [Microsoft](https://devblogs.microsoft.com/cppblog/addresssanitizer-continue_on_error/)
- [Google](https://github.com/google/sanitizers/wiki/AddressSanitizer)
- [Stackoverflow](https://stackoverflow.com/questions/22696071/how-to-make-addresssanitizer-not-stop-after-one-error-and-other-issues)
- [Github](https://github.com/google/sanitizers/wiki/AddressSanitizerFlags/81126965c19a22c0dff2ebe242a12b7a6e26b37c)
- [Llvm](https://github.com/llvm/llvm-project/blob/main/compiler-rt/lib/asan/asan_mapping.h)
- [Stacko](https://stackoverflow.com/questions/76303855/asan-stack-use-after-return-want-to-learn-more-about-the-shadow-bytes-around)
- [Micro](https://learn.microsoft.com/en-us/cpp/sanitizers/error-stack-use-after-return?view=msvc-170)
