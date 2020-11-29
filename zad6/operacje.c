#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacje_matematyczne.h"


struct Macierz* wczytaj(char *fnazwa)
{   
    FILE *fin;
    struct Macierz *m;
    int i, j;

    fin = fopen(fnazwa, "r");
   
    m = (struct Macierz*)malloc (sizeof(struct Macierz));
    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

    m->tab = (float**)malloc(sizeof(float*)* m->r);
    for (i = 0; i < m->r; i++)
    { 
        m->tab[i] = malloc(sizeof(float)* m->c);
        for(j = 0; j<m->c; j++ ){
            m->tab[i][j] = i + j + 1;
        }
        
    }

    for (i=0; i<m->r; i++){
        for(j=0; j<m->c;j++){
            fscanf(fin,"%f", &m->tab[i][j]);
        }
    }
    fclose(fin);

    return m;
}

void wypisz(struct Macierz m)
{
    int i, j;
    printf("[ ");
    for (i = 0; i < m.r; i++)
    {
        for (j = 0; j < m.c; j++)
        {
            printf("%5.1f ", m.tab[i][j]);
        }
        if (i < (m.r - 1))
            printf("\n  ");
    }
    printf("]\n");
}



void zapisz(char nazwa[], struct Macierz m)
{
    FILE *fout = fopen(nazwa, "w");
    int i, j;
    fprintf(fout, "%d\n%d\n", m.r, m.c);
    for (i = 0; i < m.r; i++)
    {
        for (j = 0; j < m.c; j++)
        {
            fprintf(fout, "%f\n", m.tab[i][j]);
        }
    }
    fclose(fout);
}

void zwolnij(struct Macierz *m)
{
     for (int i=0; i< m->r; i++)
    {
        free(m->tab[i]);
    }
    free(m->tab);
    free(m);
}


