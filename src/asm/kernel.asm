section .multiboot
align 4
    dd 0x1BADB002           ; Magic
    dd 0x00                 ; Flags
    dd -(0x1BADB002 + 0x00) ; Checksum [-(magic + flags)]

; END SECTION .multiboot

section .bss
align 4
    stack_bottom:
    resb 8192   ; 8 KiB Initial Stack
    stack_top:

; END SECTION .bss

section .text

global start
extern kmain

start:
    mov esp, stack_top
    call kmain
    cli
    .hang:  hlt
            jmp .hang

; END SECTION .text