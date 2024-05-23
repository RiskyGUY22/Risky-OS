#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

void heap_init(void* heap_start, size_t heap_size);
void* kmalloc(size_t size);
void kfree(void* ptr);

#endif // HEAP_H

