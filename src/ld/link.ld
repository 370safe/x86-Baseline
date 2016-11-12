OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS {
    . = 1M;
    
    /* Executable Code */
    .text : {
        *(.multiboot) 
        *(.text) 
    }
    
    /* Read Only Data */
    .rodata : {
        *(.rodata)
    }

    /* Read-Write Initialized Data */
    .data : { 
        *(.data)
    }

    /* Read-Write Uninitialized Data (also stack) */
    .bss  : { 
        *(.bss)
    }
 }