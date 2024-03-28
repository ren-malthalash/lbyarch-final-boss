@echo off
nasm -f elf64 nasm_dot_product.asm
gcc -Wall main.c nasm_dot_product.o
a.exe