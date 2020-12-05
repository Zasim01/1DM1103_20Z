#include "baza.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

student *wczytaj_studentow(FILE *fin)
{
    char bufor[255];
    int n, i;
    char *s;
    student *last_student = NULL;
    student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i = 0; i < n; i++)
    {

        student *stud = (student *)malloc(sizeof(student));
        stud->nast = NULL;

        if (last_student != NULL)
            last_student->nast = stud;
        else
            glowa = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

przedmiot *wczytaj_przedmiot(FILE *fin)
{
    char bufor[255];
    int n, i;
    char *s;
    przedmiot *last_przedmiot = NULL;
    przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i = 0; i < n; i++)
    {

        przedmiot *przed = (przedmiot *)malloc(sizeof(przedmiot));
        przed->nast = NULL;

        if (last_przedmiot != NULL)
            last_przedmiot->nast = przed;
        else
            glowa = przed;
        last_przedmiot = przed;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przed->kod_przedmiotu = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(przed->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        przed->nazwa = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(przed->nazwa, s);

        s = strtok(NULL, ";");
        przed->semestr = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(przed->semestr, s);
    }

    return glowa;
}

ocena *wczytaj_ocene(FILE *fin)
{

    char bufor[255];
    int n, i;
    char *s;
    ocena *last_ocena = NULL;
    ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i = 0; i < n; i++)
    {

        ocena *_ocena = (ocena *)malloc(sizeof(ocena));
        _ocena->nast = NULL;

        if (last_ocena != NULL)
            last_ocena->nast = _ocena;
        else
            glowa = _ocena;
        last_ocena = _ocena;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        _ocena->nr_albumu = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(_ocena->nr_albumu, s);

        s = strtok(NULL, ";");
        _ocena->kod = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(_ocena->kod, s);

        s = strtok(NULL, ";");
        _ocena->liczba = atof(s);

        s = strtok(NULL, ";");
        _ocena->kometarz = (char *)malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(_ocena->kometarz, s);
    }

    return glowa;
}

sbaza *wczytaj_baze(char *nazwa_pliku)
{
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL)
    {
        printf("Nie mogę otworzyć pliku %s.\n", nazwa_pliku);
        exit(-1);
    }
    sbaza *baza = (sbaza *)malloc(sizeof(sbaza));
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmiot(fin);
    baza->lista_ocen = wczytaj_ocene(fin);

    fclose(fin);
    return baza;
}

sbaza *zapisz_baze(char *nazwa_pliku, sbaza *baza)
{
    int a = ile_studentow(baza);
    int b = ile_przedmiotow(baza);
    int c = ile_ocen(baza);

    FILE *fin = fopen(nazwa_pliku, "w+");
    student *stud = baza->lista_studentow;
    przedmiot *przed = baza->lista_przedmiotow;
    ocena *_ocena = baza->lista_ocen;

    fprintf(fin, "%d\n", a);
    while (stud != NULL)
    {
        fprintf(fin, "%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }

    fprintf(fin, "%d\n", b);
    while (przed != NULL)
    {
        fprintf(fin, "%s;%s;%s\n", przed->kod_przedmiotu, przed->nazwa, przed->semestr);
        przed = przed->nast;
    }

    fprintf(fin, "%d\n", c);
    while (_ocena != NULL)
    {
        fprintf(fin, "%s;%s;%f;%s\n", _ocena->nr_albumu, _ocena->kod, _ocena->liczba, _ocena->kometarz);
        _ocena = _ocena->nast;
    }
     
    fclose(fin);
    return NULL;
}

int ile_studentow(sbaza *baza)
{
    int n = 0;
    student *stud = baza->lista_studentow;
    while (stud != NULL)
    {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_przedmiotow(sbaza *baza)
{
    int n = 0;
    przedmiot *przed = baza->lista_przedmiotow;
    while (przed != NULL)
    {
        n++;
        przed = przed->nast;
    }
    return n;
}

int ile_ocen(sbaza *baza)
{
    int n = 0;
    ocena *_ocena = baza->lista_ocen;
    while (_ocena != NULL)
    {
        n++;
        _ocena = _ocena->nast;
    }
    return n;
}

void listuj_studentow(sbaza *baza)
{
    student *stud = baza->lista_studentow;
    while (stud != NULL)
    {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void dodaj_studentow(sbaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email)
{
    student *nowy = (student *)malloc(sizeof(student));
    student *kolejny = NULL;
    nowy->nast = NULL;

    nowy->imie = (char *)malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);

    nowy->nazwisko = (char *)malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);

    nowy->nr_albumu = (char *)malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    nowy->email = (char *)malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);
    kolejny = baza->lista_studentow;

    if (ile_studentow(baza) == 0)
    {
        baza->lista_studentow = nowy;
    }

    else
    {
        for (int i = 1; i < ile_studentow(baza); i++)
        {
            kolejny = kolejny->nast;
        }
        kolejny->nast = nowy;
    }
}

void dodaj_przedmiot(sbaza *baza, char *kod_przedmiotu, char *nazwa, char *semestr)
{
    przedmiot *nowy = (przedmiot *)malloc(sizeof(przedmiot));
    przedmiot *kolejny = NULL;
    nowy->nast = NULL;
    nowy->kod_przedmiotu = (char *)malloc(sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(nowy->kod_przedmiotu, kod_przedmiotu);

    nowy->nazwa = (char *)malloc(sizeof(char) * (strlen(nazwa) + 1));
    strcpy(nowy->nazwa, nazwa);

    nowy->semestr = (char *)malloc(sizeof(char) * (strlen(semestr) + 1));
    strcpy(nowy->semestr, semestr);

    kolejny = baza->lista_przedmiotow;

    if (ile_przedmiotow(baza) == 0)
    {
        baza->lista_przedmiotow = nowy;
    }

    else
    {
        for (int i = 1; i < ile_przedmiotow(baza); i++)
        {
            kolejny = kolejny->nast;
        }
        kolejny->nast = nowy;
    }
}

void dodaj_studenta_do_przed(sbaza *baza, char *nr_albumu, char *kod, float liczba, char *kometarz)
{
    ocena *nowy = (ocena *)malloc(sizeof(ocena));
    ocena *kolejny = NULL;
    nowy->nast = NULL;
    nowy->nr_albumu = (char *)malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    nowy->kod = (char *)malloc(sizeof(char) * (strlen(kod) + 1));
    strcpy(nowy->kod, kod);

    nowy->liczba = liczba;

    nowy->kometarz = (char *)malloc(sizeof(char) * (strlen(kometarz) + 1));
    strcpy(nowy->kometarz, kometarz);

    kolejny = baza->lista_ocen;

    if (ile_ocen(baza) == 0)
    {
        baza->lista_ocen = nowy;
    }

    else
    {
        for (int i = 1; i < ile_ocen(baza); i++)
        {
            kolejny = kolejny->nast;
        }
        kolejny->nast = nowy;
    }
}

void zwolnij_student(student *s)
{
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_przedmiot(przedmiot *s)
{
    free(s->kod_przedmiotu);
    free(s->nazwa);
    free(s->semestr);
    free(s);
}

void zwolnij_ocena(ocena *s)
{
    free(s->nr_albumu);
    free(s->kod);
    free(s->kometarz);
    free(s);
}

void zwolnij_liste_studentow(student *s)
{
    student *n;
    while (s != NULL)
    {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_liste_przedmiotow(przedmiot *s)
{
    przedmiot *n;
    while (s != NULL)
    {
        n = s->nast;
        zwolnij_przedmiot(s);
        s = n;
    }
}

void zwolnij_liste_ocen(ocena *s)
{
    ocena *n;
    while (s != NULL)
    {
        n = s->nast;
        zwolnij_ocena(s);
        s = n;
    }
}

void zwolnij(sbaza *baza)
{
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}
