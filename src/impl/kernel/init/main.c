#include <print.h>
#include <heap.h>

extern char end; // Defined by the linker script
#define HEAP_START ((void*)&end)

void kernel_main() {

    print_clear();
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    print_str("Welcome to Risky OS! \nThis is a work in progress Operating System \nAll of the code is open source at: \nhttps://github.com/RiskyGUY22/Risky-OS\n\n");

    new_shell();


	// Initialize the heap with a fixed size, e.g., 64 KB
    heap_init(HEAP_START, 64 * 1024);

    // Example usage
    void* ptr1 = kmalloc(100);
    void* ptr2 = kmalloc(200);

    kfree(ptr1);
    kfree(ptr2);

    // Your main loop or other initialization code
    while (1) {
        // Infinite loop to keep the kernel running
    }

}
