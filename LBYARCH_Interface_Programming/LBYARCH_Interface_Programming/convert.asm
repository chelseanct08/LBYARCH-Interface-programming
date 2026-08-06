; convert.asm

section .data
    var1 dd 255.0

section .text
bits 64
default rel

global imgCvtGrayFloatToInt

imgCvtGrayFloatToInt:

    xor r10d, r10d
    movss xmm1, [var1]

L1:

    cmp r10d, r8d
    jge L2

    movss xmm0, [rcx + r10*4]
    mulss xmm0, xmm1

    cvttss2si eax, xmm0 ; cvtss2si

    mov [rdx + r10], al
    inc r10d

    jmp L1

L2:

    ret