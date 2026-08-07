; convert.asm

section .data
    var1 dd 255.0   ; constant multiplier

section .text
bits 64
default rel

global convert

convert:
    xor r10d, r10d          ; initialize loop counter
    movss xmm1, [var1]      ; load 255.0

L1:
    cmp r10d, r8d
    jge L2

    movss xmm0, [rcx + r10*4]   ; load input pixel
    mulss xmm0, xmm1            ; multiply by 255.0

    ; cvtss2si
    cvttss2si eax, xmm0    ; convert float to integer

    mov [rdx + r10], al    ; store output 
    inc r10d

    jmp L1

L2:

    ret