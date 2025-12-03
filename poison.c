#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Include ASan header (assuming it's available on your system)
#include <sanitizer/asan_interface.h>

#define HEAP_SIZE (1024 * 1024) // 1MB custom heap
char custom_heap[HEAP_SIZE];

void init_heap() {
    // Poison the entire custom heap initially
    __asan_poison_memory_region(custom_heap, HEAP_SIZE);
}

void* custom_alloc(size_t size) {
    // Find a suitable unpoisoned chunk (simplified for example)
    // In a real allocator, you'd manage free lists and check for size
    void* ptr = malloc(size); // Use malloc to find an available chunk
    if (ptr) {
        // Unpoison the allocated chunk
        __asan_unpoison_memory_region(ptr, size);
    }
    return ptr;
}

void custom_free(void* ptr, size_t size) {
    if (ptr) {
        // Poison the memory again before freeing
        __asan_poison_memory_region(ptr, size);
        free(ptr);
    }
}

int main() {
    init_heap();

    // Allocate memory using custom allocator
    size_t size = 50;
    void* data = custom_alloc(size);

    if (data) {
        // Use the memory
        strcpy((char*)data, "This is some data");
        printf("Data: %s\n", (char*)data);

        // Free the memory
        custom_free(data, size);
    }

    // Attempting to use data after free will be caught by ASan
	__asan_describe_address(data);
     //printf("%s", (char*)data); // This would cause an ASan error
    
    return 0;
}
