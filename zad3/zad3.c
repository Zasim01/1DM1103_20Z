#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Macierz
{
    int r;
    int c;
    float tab[20][20];
};

void wczytaj(FILE *fin, struct Macierz *m)
{
    int i, j;
    fscanf(fin, "%d", &(*m).r);
    fscanf(fin, "%d", &(*m).c);
    for (i = 0; i < (*m).r; i++)
    {
        for (j = 0; j < (*m).c; j++)
        {
            fscanf(fin, "%f", &(*m).tab[i][j]);
        }
    }
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

struct Macierz sum(struct Macierz n, struct Macierz m)
{
    struct Macierz suma;
    suma.c = n.c;
    suma.r = n.r;

    if (n.r == m.r && n.c == m.c)
    {
        for (int i = 0; i < n.r; i++)
        {
            for (int j = 0; j < n.c; j++)
            {
                suma.tab[i][j] = n.tab[i][j] + m.tab[i][j];
            }
        }
        return suma;
    }
    else
    {
        printf("We cannot sum these matrixes!");
    }
}

struct Macierz subtract(struct Macierz n, struct Macierz m)
{

    struct Macierz odejmowanie;
    odejmowanie.c = n.c;
    odejmowanie.r = n.r;

    if (n.r == m.r && n.c == m.c)
    {
        for (int i = 0; i < n.r; i++)
        {
            for (int j = 0; j < n.c; j++)
            {
                odejmowanie.tab[i][j] = n.tab[i][j] - m.tab[i][j];
            }
        }
        return odejmowanie;
    }

    else
    {
        printf("We cannot subtract these matrixes!");
    }
}

struct Macierz prod(struct Macierz n, struct Macierz m)
{

    struct Macierz pomnoz;
    pomnoz.r = n.r;
    pomnoz.c = m.c;

    if (n.c == m.r)
    {
        for (int i = 0; i < n.r; i++)
        {
            for (int j = 0; j < m.c; j++)
            {
                pomnoz.tab[i][j] = 0;
                for (int k = 0; k < n.c; k++)
                {
                    pomnoz.tab[i][j] += n.tab[i][k] * m.tab[k][j];
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

struct Macierz multiply(struct Macierz m, double k)
{
    struct Macierz przez_skalar;
    przez_skalar.r = m.r;
    przez_skalar.c = m.c;

    for (int i = 0; i < m.r; i++)
    {
        for (int j = 0; j < m.c; j++)
        {
            przez_skalar.tab[i][j] = m.tab[i][j] * k;
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

//wczytaj dwuwymiarową macierz: r,c,liczby

int main(int argc, char *argv[])
{
    // Wczytaj macierz A
    struct Macierz macA;
    FILE *a = fopen(argv[2], "r");
    wczytaj(a, &macA);

    // Wczytaj macierz B
    struct Macierz macB;
    FILE *b = fopen(argv[3], "r");
    wczytaj(b, &macB);

    struct Macierz mac_wynik;

    // Sprawdzanie, które działanie ma wykonać program
    if (strcmp(argv[1], "sum") == 0)
    {
        mac_wynik = sum(macA, macB);
    }
    else if (strcmp(argv[1], "subtract") == 0)
    {
        mac_wynik = subtract(macA, macB);
    }
    else if (strcmp(argv[1], "prod") == 0)
    {
        mac_wynik = prod(macA, macB);
    }
    else if (strcmp(argv[1], "multiply") == 0)
    {
        mac_wynik = multiply(macA, atof(argv[5]));
    }
    else if (strcmp(argv[1], "norm") == 0)
    {
        float s = norm(macA);
        printf("Norma macierzy to: %f", norm(macA));
    }

    else
    {
        printf("Nie rozpoznano wskazanego działania");
    }

    if (argv[4] != NULL)
    {
        zapisz(argv[4], mac_wynik);
    }

    wypisz(mac_wynik);

    fclose(a);
    fclose(b);
    return 0;
}