
#include<stdio.h>
#include <math.h>
#include"operacje_matematyczne.h"
# include <stdlib.h>


struct Macierz* sum(struct Macierz n, struct Macierz m)
{
    struct Macierz *suma;
    suma = (struct Macierz*)malloc (sizeof(struct Macierz));
    suma->c = n.c;
    suma->r = n.r;

    suma->tab = (float**)malloc(sizeof(float*)* suma->r);
    for (int i = 0; i < suma->r; i++)
    { 
        suma->tab[i] = malloc(sizeof(float)* suma->c);
        for(int j = 0; j<suma->c; j++ ){
            suma->tab[i][j] = i + j + 1;
        }
        
    }
    if (n.r == m.r && n.c == m.c)
    {
        for (int i = 0; i < n.r; i++)
        {
            for (int j = 0; j < n.c; j++)
            {
                suma->tab[i][j] = n.tab[i][j] + m.tab[i][j];
            }
        }
        return suma;
    }
    else
    {
        printf("We cannot sum these matrixes!");
    }
}

struct Macierz *subtract(struct Macierz n, struct Macierz m)
{;

    struct Macierz *odejmowanie;
    odejmowanie = (struct Macierz*)malloc (sizeof(struct Macierz));
    odejmowanie->c = n.c;
    odejmowanie->r = n.r;

    odejmowanie->tab = (float**)malloc(sizeof(float*)* odejmowanie->r);
    for (int i = 0; i < odejmowanie->r; i++)
    { 
        odejmowanie->tab[i] = malloc(sizeof(float)* odejmowanie->c);
        for(int j = 0; j<odejmowanie->c; j++ ){
            odejmowanie->tab[i][j] = i + j + 1;
        }
        
    }

    if (n.r == m.r && n.c == m.c)
    { 
        for (int i = 0; i < n.r; i++)
        {
            for (int j = 0; j < n.c; j++)
            {
                odejmowanie->tab[i][j] = n.tab[i][j] - m.tab[i][j];
            }
        }
        return odejmowanie;
    }

    else
    {
        printf("We cannot subtract these matrixes!");
    }
}

struct Macierz *prod(struct Macierz n, struct Macierz m)
{

    struct Macierz *pomnoz;
    pomnoz = (struct Macierz*)malloc (sizeof(struct Macierz));
    pomnoz->r = n.r;
    pomnoz->c = m.c;

    pomnoz->tab = (float**)malloc(sizeof(float*)* pomnoz->r);
    for (int i = 0; i < pomnoz->r; i++)
    { 
        pomnoz->tab[i] = malloc(sizeof(float)* pomnoz->c);
        for(int j = 0; j<pomnoz->c; j++ ){
            pomnoz->tab[i][j] = i + j + 1;
        }
        
    }

    if (n.c == m.r)
    {
        for (int i = 0; i < n.r; i++)
        {
            for (int j = 0; j < m.c; j++)
            {
                pomnoz->tab[i][j] = 0;
                for (int k = 0; k < n.c; k++)
                {
                    pomnoz->tab[i][j] += n.tab[i][k] * m.tab[k][j];
                }
            }
        }
        return pomnoz;
    }

    else
    {
        printf("We cannot multipy these matrixes!");
    }
}

// Przyjmuję, że liczba k bedzie czwartym argumentem w lini komend
//(pierwszy:jakie działanie, drugi:pierwszy plik, trzeci:drugi plik, czwarty:liczba k

struct Macierz*
 multiply(struct Macierz m, double k)
{
    struct Macierz *przez_skalar;
    przez_skalar = (struct Macierz*)malloc (sizeof(struct Macierz));
    przez_skalar->r = m.r;
    przez_skalar->c = m.c;

    przez_skalar->tab = (float**)malloc(sizeof(float*)* przez_skalar->r);
    for (int i = 0; i < przez_skalar->r; i++)
    { 
        przez_skalar->tab[i] = malloc(sizeof(float)* przez_skalar->c);
        for(int j = 0; j<przez_skalar->c; j++ ){
            przez_skalar->tab[i][j] = i + j + 1;
        }
        
    }

    for (int i = 0; i < m.r; i++)
    {
        for (int j = 0; j < m.c; j++)
        {
            przez_skalar->tab[i][j] = m.tab[i][j] * k;
        }
    }
    return przez_skalar;
}

float norm(struct Macierz m)
{
    float s = 0;
    for (int i = 0; i < m.r; i++)
    {
        for (int j = 0; j < m.c; j++)
        {
            s += m.tab[i][j] * m.tab[i][j];
        }
    }
    return sqrt(s);
}