#!/bin/bash
VALGRIND_LOG="valgrind.log"
QEMU_COMMAND="qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso"

echo "Running QEMU with Valgrind..."
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $QEMU_COMMAND > $VALGRIND_LOG 2>&1

if grep -q "definitely lost" $VALGRIND_LOG; then
    echo "Memory leaks detected:"
    grep "definitely lost" $VALGRIND_LOG
else
    echo "No memory leaks detected."
fi

