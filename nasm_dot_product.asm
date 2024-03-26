BITS 64

section .data

section .text
global nasm_dot_product
nasm_dot_product:
    ;push rbp
    addsd xmm0, xmm1
    ret