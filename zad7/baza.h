#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _student *nast;

}student;

typedef struct _przedmiot {
    char * kod_przedmiotu;
    char * nazwa;
    char * semestr;

    struct _przedmiot *nast;

}przedmiot;

typedef struct _ocena {
    char * nr_albumu;
    char * kod;
    float liczba;
    char * kometarz;

    struct _ocena *nast;

}ocena;

typedef struct _sbaza{

    student *lista_studentow; 
    przedmiot *lista_przedmiotow;
    ocena *lista_ocen;

}sbaza;



sbaza * wczytaj_baze(char *nazwa_pliku);
sbaza * zapisz_baze(char *nazwa_pliku, sbaza * baza);
void listuj_studentow (sbaza *baza);
void zwolnij (sbaza *baza);
int ile_studentow(sbaza *baza);
int ile_przedmiotow(sbaza *baza);
int ile_ocen(sbaza *baza);
void dodaj_studentow(sbaza *baza,char *imie ,char *nazwisko,char *nr_albumu,char *email);
void dodaj_przedmiot(sbaza *baza,char *kod_przedmiotu ,char *nazwa,char *semestr);
void dodaj_studenta_do_przed(sbaza *baza,char *nr_albumu, char *kod, float liczba, char * kometarz  );


#endif