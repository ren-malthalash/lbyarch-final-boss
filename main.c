//Josh Austin Mikhail T. Natividad & Christian Dave P. Tordillo | LBYARCH XX22
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <float.h>
#include "kernel.h"

#define N_LOOPS 30

extern double nasm_dot_product(int, double*, double*);
extern void* nasm_read_p(void*);


static void randomVectors(double VectorA[], double VectorB[], int V_SIZE) {
    for (unsigned int i = 0; i < V_SIZE; i++) {
        VectorA[i] = (float)rand() / (float)(RAND_MAX);
        VectorB[i] = (float)rand() / (float)(RAND_MAX);
    }
}



void run_test(int V_SIZE, double* run_c, double* run_asm) {
    double* VectorA = (double*)malloc(V_SIZE * sizeof(double));
    double* VectorB = (double*)malloc(V_SIZE * sizeof(double));

    printf("%p\n", &VectorA);
    printf("%p\n", &VectorB);

    double C_time = 0.0;
    double ASM_time = 0.0;

    int count = 0;

    //Main loop for running the kernels
    while (count < N_LOOPS) {
        /*Used to measure time between functions
        Measuring time between functions from:
        https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
        */

        //volatile to prevent compiler optimizations (messes up the output)
        volatile clock_t start = -1;
        volatile clock_t end = -1;
        volatile clock_t start2 = -1;
        volatile clock_t end2 = -1;

        //initialize vectors
        randomVectors(VectorA, VectorB, V_SIZE);

        printf("Run #%d\n", count + 1);

        //C Kernel
        //start timer
        start = clock();
        printf("C:\t%.2f\t", dot_product(V_SIZE, VectorA, VectorB));
        //end timer
        end = clock();
        printf("Time\t\t: %.10lf\n", ((double)(end - start)) / CLOCKS_PER_SEC);

        C_time = C_time + ((double)(end - start)) / CLOCKS_PER_SEC;

        //ASM Kernel
        //start timer
        start2 = clock();
        printf("ASM:\t%.2f\t", nasm_dot_product(V_SIZE, VectorA, VectorB));
        //end timer
        end2 = clock();
        printf("Time\t\t: %.10lf\n", ((double)(end2 - start2)) / CLOCKS_PER_SEC);

        ASM_time = ASM_time + ((double)(end2 - start2)) / CLOCKS_PER_SEC;

        count += 1;
        printf("--------------------------------------------------------------\n");
    }

    //Get the Average for each kernel
    *run_c = C_time / N_LOOPS;
    *run_asm = ASM_time / N_LOOPS;
}

int main() {
    srand(time(NULL));

    double run1_c, run1_asm;
    double run2_c, run2_asm;
    double run3_c, run3_asm;

    //2^20 = 1048576
    //2^24 = 16777216
    //2^28 = 268435456

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