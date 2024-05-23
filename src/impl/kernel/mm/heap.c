#include <heap.h>

typedef struct block {
    size_t size;
    struct block* next;
} block_t;

#define ALIGN4(size) (((size) + 3) & ~3)
#define BLOCK_SIZE (sizeof(block_t))

static block_t* free_list = NULL;

void heap_init(void* heap_start, size_t heap_size) {
    free_list = (block_t*)heap_start;
    free_list->size = heap_size - BLOCK_SIZE;
    free_list->next = NULL;
}

void* kmalloc(size_t size) {
    size = ALIGN4(size);
    block_t* current = free_list;
    block_t* prev = NULL;

    while (current) {
        if (current->size >= size) {
            if (current->size >= size + BLOCK_SIZE + 4) {
                block_t* new_block = (block_t*)((char*)current + BLOCK_SIZE + size);
                new_block->size = current->size - size - BLOCK_SIZE;
                new_block->next = current->next;
                current->size = size;
                current->next = new_block;
            }

            if (prev) {
                prev->next = current->next;
            } else {
                free_list = current->next;
            }

            return (char*)current + BLOCK_SIZE;
        }
        prev = current;
        current = current->next;
    }
    return NULL; // Out of memory
}

void kfree(void* ptr) {
    if (!ptr) return;

    block_t* block = (block_t*)((char*)ptr - BLOCK_SIZE);
    block->next = free_list;
    free_list = block;
}

