#include "print.h"

void kernel_main() {

    print_clear();
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    print_str("Welcome to Risky OS! \nThis is a work in progress Operating System \nAll of the code is open source at: \nhttps://github.com/RiskyGUY22/Risky-OS\n\n");

    new_shell();

}