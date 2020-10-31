#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Wczytaj pierwszy plik (A)

    FILE *fin_a = fopen(argv[1], "r");
    int A_l_wierszy = 0;
    int A_l_kolumn = 0;

    //Wczytaj liczbe wierszy dla pierwszej macierzy
    fscanf(fin_a, "%d", &A_l_wierszy);
    printf("(%d) ", A_l_wierszy);
    //Wczytaj liczbe kolumn dla pierwszej macierzy
    fscanf(fin_a, "%d", &A_l_kolumn);
    //printf("%d\n", l_kolumn);

    // Wczytaj pierwszą macierz
    float mac_A[A_l_wierszy][A_l_kolumn];
    for (int i = 0; i < A_l_wierszy; i++)
    {
        for (int j = 0; j < A_l_kolumn; j++)
        {
            fscanf(fin_a, "%f", &mac_A[i][j]);
        }
    }
    fclose(fin_a);

    // Wczytaj drugi plik (x)

    FILE *fin_x = fopen(argv[2], "r");
    int x_l_wierszy = 0;
    int x_l_kolumn = 0;

    //Wczytaj liczbe wierszy dla wektora
    fscanf(fin_x, "%d", &x_l_wierszy);
    //Wczytaj liczbe kolumn dla wektora
    fscanf(fin_x, "%d", &x_l_kolumn);

    //Wczytaj wektor
    float mac_x[x_l_wierszy][x_l_kolumn];
    for (int i = 0; i < x_l_wierszy; i++)
    {
        for (int j = 0; j < x_l_kolumn; j++)
        {
            fscanf(fin_x, "%f", &mac_x[i][j]);
        }
    }
    fclose(fin_x);

    //Mnożenie macierzy przez wektor
    float wynik[A_l_wierszy][x_l_kolumn];
    for (int k = 0; k < A_l_wierszy; k++)
    {
        float suma = 0;
        for (int l = 0; l < A_l_kolumn; l++)
        {
            suma = suma + mac_A[k][l] * mac_x[l][0];
        }

        wynik[k][0] = suma;
    }

    // Wypisywanie wyniku
    printf("[");
    for (int i = 0; i < A_l_wierszy; i++)
    {
        for (int j = 0; j < x_l_kolumn; j++)
        {
            printf(" %f ", wynik[i][j]);
        }
    }
    printf("]");
    printf("\n");
}