global start

section .multiboot_header
header_start:
    dd 0xe85250d6                ; magic number (multiboot 2 spec)
    dd 0                         ; architecture 0
    dd header_end - header_start ; header length
    
    ; checksum
    dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

    ; required end tag
    dw 0    ; type
    dw 0    ; flags
    dd 8    ; size
header_end:

section .text
extern Rheinheart__method__kernel
bits 32
start:
    mov dword [0xb8000], 0x026b024f
    
    call Rheinheart__method__kernel
    
    hlt ;stop execution