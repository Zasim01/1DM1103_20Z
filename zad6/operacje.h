#ifndef OPERACJE
#define OPERACJE



struct Macierz* wczytaj(char *fnazwa);

void wypisz(struct Macierz m);

void zapisz(char nazwa[], struct Macierz m);

void zwolnij(struct Macierz *m);

#endif