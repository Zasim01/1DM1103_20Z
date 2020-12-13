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

    struct _student *poprz;
    struct _student *nast;
    

}student;

typedef struct _przedmiot {
    char * kod_przedmiotu;
    char * nazwa;
    char * semestr;

    struct _przedmiot *poprz;
    struct _przedmiot *nast;

}przedmiot;

typedef struct _ocena {
    char * nr_albumu;
    char * kod;
    float liczba;
    char * kometarz;

    struct _ocena *nast;
    struct _ocena *poprz;
}ocena;

typedef struct _sbaza{

    student *lista_studentow; 
    przedmiot *lista_przedmiotow;
    ocena *lista_ocen;

}sbaza;



sbaza * wczytaj_baze(char *nazwa_pliku);
sbaza * zapisz_baze(char *nazwa_pliku, sbaza * baza);
void listuj_studentow (sbaza *baza);
void listuj_studentow_od_konca(sbaza *b);
void zwolnij (sbaza *baza);
int ile_studentow(sbaza *baza);
int ile_przedmiotow(sbaza *baza);
int ile_ocen(sbaza *baza);
void dodaj_studentow(sbaza *baza,char *imie ,char *nazwisko,char *nr_albumu,char *email);
void dodaj_przedmiot(sbaza *baza,char *kod_przedmiotu ,char *nazwa,char *semestr);
void dodaj_studenta_do_przed(sbaza *baza,char *nr_albumu, char *kod, float liczba, char * kometarz  );

student *sortuj_przez_wybieranie_najwiekszy(student *glowa);
student *sortuj_przez_wybieranie_najmniejszy(student *glowa);


void listuj_przedmioty(sbaza *baza);
void listuj_oceny(sbaza * baza);
void wypisz_rekurencyjnie_przedmioty_od_konca(przedmiot *glowa);
przedmiot * sortuj_przez_wybieranie_najmniejszy_przed(przedmiot *glowa);
//przedmiot *sortuj_przez_wybieranie_najmniejszy_przed_nazwa(przedmiot *glowa);

przedmiot * sortuj_przed_przez_wybieranie_ros_nazw(przedmiot *glowa);


ocena *filtruj_przedmiot(ocena *glowa, char *kod_przedmiotu);
void wypisz_rekurencyjnie_oceny(ocena *glowa);



#endif