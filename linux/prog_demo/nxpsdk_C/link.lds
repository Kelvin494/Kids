SECTIONS{
    . = 0X87800000;
    .text :
    {
        midobj/start.o 
        midobj/ainm.o 
        *(.text)
    }
    .rodata ALIGN(4) : {*(.rodata*)} 
    .data ALIGN(4) : { *(.data) } 
    __bss_start = .; 
    .bss ALIGN(4) : { *(.bss) *(COMMON) } 
    __bss_end = .;
}