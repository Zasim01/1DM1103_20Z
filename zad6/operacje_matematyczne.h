#ifndef OPERACJE_MATEMATYCZNE
#define OPERACJE_MATEMATYCZNE 
#include <stdlib.h>

typedef struct Macierz
{
    float **tab;
    int r;
    int c;
   
}mat;


struct Macierz* sum(struct Macierz n, struct Macierz m);

struct Macierz* subtract(struct Macierz n, struct Macierz m);

struct Macierz* prod(struct Macierz n, struct Macierz m);

struct Macierz* multiply(struct Macierz m, double k);

float norm (struct Macierz m);

#endif