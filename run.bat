@echo off
nasm -f win64 nasm_dot_product.asm -o nasm_dot_product.obj
gcc -Wall main.c nasm_dot_product.obj
a.exe
pause