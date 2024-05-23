ENTRY(start)

SECTIONS
{

	. = 1M;

	end = .;
	
    .rodata : { *(.rodata) }
    .data : { *(.data) }
    .bss : { *(.bss) }

	.boot :
	{
		KEEP(*(.multiboot_header))
	}

	.text :
	{
		*(.text)

	}



}
