double dot_product(unsigned int n, double VectorA[], double VectorB[]) {
    double sdot = 0.0f;
    for (unsigned int i = 0; i <= n; i++)
    {
        sdot += VectorA[i] * VectorB[i];
    }
    
    return sdot;
}