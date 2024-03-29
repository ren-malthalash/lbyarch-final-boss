#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <float.h>
#include "kernel.h"

//CHANGE THIS VALUE TO ADJUST VECTOR SIZE
//for reference:
//2^20 = 1048576
//2^24 = 16777216
//2^30 = 1073741824
#define V_SIZE 20
#define N_LOOPS 30

extern double nasm_dot_product(int, double*, double*);
extern void* nasm_read_p(void*);

void randomVectors(long double VectorA[], double VectorB[]) {
    int i;
    for (i = 0; i < V_SIZE; i++) {

        VectorA[i] = 1.0;
        VectorB[i] = 1.0;
    }
    return;
}



int main(int number) {
    double* VectorA = (double*)malloc(V_SIZE * sizeof(double));
    double* VectorB = (double*)malloc(V_SIZE * sizeof(double));

    /*Used to measure time between functions
    Measuring time between functions from:
    https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
    */
    clock_t start = -1;
    clock_t end = -1;


    randomVectors(VectorA, VectorB);

    
    printf("%p\n", &VectorA);
    printf("%p\n", &VectorB);

    double C_time = 0.0;
    double ASM_time = 0.0;

    int count_c = 0;

    while (count_c < N_LOOPS) {
        //start timer
        start = clock();
        printf("C Run #%d \t: %.2f \n", count_c + 1, dot_product(V_SIZE, VectorA, VectorB));
        //end timer
        end = clock();
        printf("Time\t\t: %.10lf\n", ((double)(end - start)) / CLOCKS_PER_SEC);

        C_time = C_time + ((double)(end - start)) / CLOCKS_PER_SEC;

        count_c = count_c + 1;
    }

    printf("%p\n", nasm_read_p(&VectorA));
    printf("%p\n", nasm_read_p(&VectorB));



    int count_asm = 0;

    while (count_asm < N_LOOPS) {
        //start timer
        start = clock();
        printf("ASM Run #%d \t: %.2f \n", count_asm + 1, nasm_dot_product(V_SIZE, VectorA, VectorB));
        //end timer
        end = clock();
        printf("Time\t\t: %.10lf\n", ((double)(end - start)) / CLOCKS_PER_SEC);

        ASM_time = ASM_time + ((double)(end - start)) / CLOCKS_PER_SEC;

        count_asm = count_asm + 1;
    }

    printf("Average Time (C):\t%.10lf seconds\n", C_time / N_LOOPS);
    printf("Average Time (NASM):\t%.10lf seconds\n", ASM_time / N_LOOPS);

    return 0;
}

