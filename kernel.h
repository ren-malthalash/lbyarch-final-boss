double dot_product(unsigned int n, double VectorA[], double VectorB[]) {
    double sdot = 0.0f;
    unsigned int i;

    for (i = 0; i < n; i++)
    {
        sdot += VectorA[i] * VectorB[i];
    }

    return sdot;
}