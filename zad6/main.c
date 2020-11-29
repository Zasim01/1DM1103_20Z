#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "operacje_matematyczne.h"
#include "operacje.h"



int main(int argc, char **argv)
{    
    struct Macierz *macA;
    macA = wczytaj(argv[2]);
    wypisz(*macA);
    
    struct Macierz *macB; 
    macB = wczytaj(argv[3]);
    wypisz(*macB);


    struct Macierz *mac_wynik;

    // Sprawdzanie, które działanie ma wykonać program
    if (strcmp(argv[1], "sum") == 0)
    {      
        mac_wynik = sum(*macA, *macB);
        wypisz(*mac_wynik);
    }
    else if (strcmp(argv[1], "subtract") == 0)
    {
        mac_wynik = subtract(*macA, *macB);
        wypisz(*mac_wynik);
    }
    else if (strcmp(argv[1], "prod") == 0)
    {
        mac_wynik = prod(*macA, *macB);
        wypisz(*mac_wynik);
    }
    else if (strcmp(argv[1], "multiply") == 0)
    {
        mac_wynik = multiply(*macA, atof(argv[4]));
        wypisz(*mac_wynik);
    }
    else if (strcmp(argv[1], "norm") == 0)
     {
        float s = norm(*macA);
        printf("Norma macierzy to: %f", norm(*macA));
     }

    else
    {
        printf("Nie rozpoznano wskazanego działania");
    }

    // if (argv[4] != NULL)
    // {
    //     zapisz(argv[4], *mac_wynik);
    // }

    
    zwolnij(macA);
    zwolnij(macB);


    return 0;
}