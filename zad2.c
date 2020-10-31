#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Wczytaj pierwszy plik
    FILE *fin_m = fopen(argv[1], "r");

    int l_wierszy = 0;
    int l_kolumn = 0;

    //Wczytaj liczbe wierszy dla pierwszej macierzy
    fscanf(fin_m, "%d", &l_wierszy);
    printf("(%d) ", l_wierszy);

    //Wczytaj liczbe kolumn dla pierwszej
    fscanf(fin_m, "%d", &l_kolumn);
    //printf("%d\n", l_kolumn);

    float mat_m[l_wierszy][l_kolumn];

    for (int i = 0; i < l_wierszy; i++)
    {
        for (int j = 0; j < l_kolumn; j++)
        {
            fscanf(fin_m, "%f", &mat_m[i][j]);
            //printf("%f ", mat_m[i][j]);
        }
        //printf("\n");
    }
    fclose(fin_m);

    // Wczytaj folder wektor.txt
    FILE *fin_w = fopen(argv[2], "r");

    int w_l_wierszy = 0;
    int w_l_kolumn = 0;

    //Wczytaj liczbe wierszy dla wektor
    fscanf(fin_w, "%d", &w_l_wierszy);
    //printf("%d\n", w_l_wierszy);

    //Wczytaj liczbe kolumn dla wektor
    fscanf(fin_w, "%d", &w_l_kolumn);
    //printf("%d\n", w_l_kolumn);

    float mat_w[w_l_wierszy][w_l_kolumn];

    for (int i = 0; i < w_l_wierszy; i++)
    {
        for (int j = 0; j < w_l_kolumn; j++)
        {
            fscanf(fin_w, "%f", &mat_w[i][j]);
            //printf("%f ", mat_w[i][j]);
        }
        //printf("\n");
    }
    fclose(fin_w);

    //Mnożenie
    float suma = 0;
    float mac_wynik[l_wierszy][1];

    printf("[ ");
    for (int k = 0; k < l_wierszy; k++)
    {   
       suma=0;
       for (int l = 0; l < l_kolumn; l++)
       {
           suma = suma + mat_m[k][l] * mat_w[l][0];
       }
    
       mac_wynik[k][0] = suma;
       printf("%f,", mac_wynik[k][0]);
    }  printf (" ]");

}