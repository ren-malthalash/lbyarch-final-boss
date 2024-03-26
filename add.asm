global _add
extern puts

section .data
msg: db "Hello World", 10, 0
section .text
_add:
    ;write your code here
    sub     rsp, 28h
    mov     rcx, msg
    call    puts
    add     rsp, 28h
    ret