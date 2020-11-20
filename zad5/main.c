#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"
#include "dziekanat.h"


int main(int argc, char** argv)
{
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);
    //wypisz(dane, ile);
    if (strcmp(argv[2], "najlepszy_student") == 0)
    {
        najlepszy_student(dane,ile);
    }
    else if(strcmp(argv[2], "srednia") == 0)
    {
        srednia(dane,ile);
    }
    else printf ("nie ma takiej funkcji");

    return 0;
}