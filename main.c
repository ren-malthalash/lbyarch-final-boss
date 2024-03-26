#include <stdio.h>
#include <string.h>
#include <float.h>
#include "kernel.h"

extern double nasm_dot_product(int, double, double);

int main() {

    unsigned int n = 3;

    double VectorA[n];
    double VectorB[n];

    memset(VectorA, 0.0f, n*sizeof(double));
    memset(VectorB, 0.0f, n*sizeof(double));

    VectorA[0] = 1.0;
    VectorA[1] = 2.0;
    VectorA[2] = 3.0;

    VectorB[0] = 1.0;
    VectorB[1] = 2.0;
    VectorB[2] = 3.0;

    printf("Hello World: %.2f\n", dot_product(3, VectorA, VectorB));


    printf("Hello World: %.2f\n", nasm_dot_product(3.0, 3.0));

    getchar();

    return 0;
}