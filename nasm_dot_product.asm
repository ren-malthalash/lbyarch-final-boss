BITS 64

; rcx
; rdx
; r8

section .data
section .text
extern printf
global nasm_read_p
global nasm_dot_product

nasm_dot_product:
    ; rdx VectorA
    ; r8 VectorB
    ; mov rcx, rcx
    xor rbx, rbx
    avx vxorps xmm0,xmm0,xmm0
    

dot:
    movsd xmm1, [rdx + rbx]
    mulsd xmm1, [r8 + rbx]
    addsd xmm0, xmm1
    add rbx, 8
    loop dot

    ret

nasm_read_p:
    mov rax, rcx
    ret