# Instructions

1. nasm -f win64 nasm_dot_product.asm -o nasm_dot_product.obj
2. gcc -Wall main.c nasm_dot_product.obj
3. a.exe

# Comparative execution time and short analysis of the performance of the kernels

<table>
  <tr>
    <th>Vector Size</th>
    <th>C Average Execution Time (s)</th>
    <th>ASM Average Execution Time (s)</th>
  </tr>
  <tr>
    <td>2<sup>20</sup></td>
    <td>0.0044666667</td>
    <td>0.0020000000</td>
  </tr>
  <tr>
    <td>2<sup>24</sup></td>
    <td>0.0573333333</td>
    <td>0.0434000000</td>
  </tr>
  <tr>
    <td>2<sup>28</sup></td>
    <td>0.7938666667</td>
    <td>0.4915000000</td>
</table>

![results](.\readme_images\image.png)


# Program Output with Correctness Check
For each run of the kernel, the result `sdot` and the execution time were printed. The vectors were set to a random value where `VectorA == VectorB`. As we can see from the results below, it can be observed that the resulting values are equal when run on both C and ASM. It can also be observed that the C and ASM kernels are accessing the same memory address based on the printed addresses before running the repeated tests.

## Correctness check for 2<sup>20</sup>
![alt text](.\readme_images\image-1.png)

## Correctness check for 2<sup>24</sup>
![alt text](.\readme_images\image-2.png)

## Correctness check for 2<sup>28</sup>
![alt text](.\readme_images\image-3.png)

# Entire Program Output with correctness check (x86-64)

