BITS 64

; rdi
; rsi
; rdx

section .data

section .text
extern printf

global nasm_dot_product
nasm_dot_product:
    ; rdx VectorA
    ; r8 VectorB
    mov rcx, rsi
    xor rbx, rbx

dot:
    movsd xmm1, [r8 + rbx]
    mulsd xmm1, [rdx + rbx]
    addsd xmm0, xmm1
    add rbx, 8;
    loop dot

    ret