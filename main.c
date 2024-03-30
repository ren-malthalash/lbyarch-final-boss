#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <float.h>
#include "kernel.h"
#define N_LOOPS 30

extern double nasm_dot_product(int, double*, double*);
extern void* nasm_read_p(void*);

void randomVectors(double VectorA[], double VectorB[], int V_SIZE) {
    int i;
    srand(time(0));
    for (i = 0; i < V_SIZE; i++) {
        float random = (float)rand() / (float)(RAND_MAX);
        VectorA[i] = random;
        VectorB[i] = random;
    }
    return;
}

void run_test(int V_SIZE, double* run_c, double* run_asm) {
    

    double* VectorA = (double*)malloc(V_SIZE * sizeof(double));
    double* VectorB = (double*)malloc(V_SIZE * sizeof(double));

    /*Used to measure time between functions
    Measuring time between functions from:
    https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
    */
    clock_t start = -1;
    clock_t end = -1;


    randomVectors(VectorA, VectorB, V_SIZE);

    
    printf("%p\n", &VectorA);
    printf("%p\n", &VectorB);

    double C_time = 0.0;
    double ASM_time = 0.0;

    int count_c = 0;

    while (count_c < N_LOOPS) {
        //start timer
        start = clock();
        printf("C Run #%d \t: %.2f \t", count_c + 1, dot_product(V_SIZE, VectorA, VectorB));
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
        printf("ASM Run #%d \t: %.2f \t", count_asm + 1, nasm_dot_product(V_SIZE, VectorA, VectorB));
        //end timer
        end = clock();
        printf("Time\t\t: %.10lf\n", ((double)(end - start)) / CLOCKS_PER_SEC);

        ASM_time = ASM_time + ((double)(end - start)) / CLOCKS_PER_SEC;

        count_asm = count_asm + 1;
    }

    *run_c = C_time / N_LOOPS;
    *run_asm = ASM_time / N_LOOPS;
}

int main() {
    //2^20 = 1048576
    //2^24 = 16777216
    //2^28 = 268435456
    double run1_c, run1_asm;
    double run2_c, run2_asm;
    double run3_c, run3_asm;

    run_test(1048576, &run1_c, &run1_asm);
    run_test(16777216,&run2_c, &run2_asm);
    run_test(268435456, &run3_c, &run3_asm);

    printf("-----------------------------------------------------------------------------------\n");
    printf("Results:\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("Vector Size\tC Average Time (s)\tASM Average Time (s)\n");
    printf("2^20       \t%.10lf\t\t%.10lf\n", run1_c, run1_asm);
    printf("2^24       \t%.10lf\t\t%.10lf\n", run2_c, run2_asm);
    printf("2^28       \t%.10lf\t\t%.10lf\n\n", run3_c, run3_asm);

    return 0;
}