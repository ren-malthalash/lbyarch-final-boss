#include <stdio.h>
#include <string.h>
#include <float.h>
#include "kernel.h"

extern double nasm_dot_product(int, double *, double *);

int main() {

    unsigned int n = 3;

    double VectorA[n];
    double VectorB[n];

    memset(VectorA, 1, n*sizeof(double));
    memset(VectorB, 1, n*sizeof(double));

    VectorA[0] = 1.0;
    VectorA[1] = 2.0;
    VectorA[2] = 3.0;

    VectorB[0] = 4.0;
    VectorB[1] = 5.0;
    VectorB[2] = 6.0;

    printf("%p\n", &VectorA);
    printf("%p\n", &VectorB);

    printf("C\t: %.2f\n", dot_product(3, VectorA, VectorB));


    printf("NASM\t: %.2f\n", nasm_dot_product(3, VectorA, VectorB));

    getchar();

    return 0;
}