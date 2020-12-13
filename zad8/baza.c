#include "baza.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

student *ostatni(student *glowa)
{
    if (glowa != NULL)
    {
        while (glowa->nast != NULL)
            glowa = glowa->nast;
        return glowa;
    }
    else
    {
        return NULL;
    }
}

void listuj_studentow_od_konca(sbaza *b)
{
    student *ogon = ostatni(b->lista_studentow);
    student *c = ogon;
    for (c = ogon; c != NULL; c = c->poprz)
    {
        printf("%s %s %s %s\n", c->imie, c->nazwisko, c->nr_albumu, c->email);
    }
}

//REKURENCJA
void wypisz_rekurencyjnie_studentow(student *glowa)
{
    if (glowa != NULL)
    {
        printf("%s %s %s %s\n", glowa->imie, glowa->nazwisko, glowa->nr_albumu, glowa->email);
        wypisz_rekurencyjnie_studentow(glowa->nast);
    }
}

void wypisz_rekurencyjnie_przedmioty_od_konca(przedmiot *glowa)
{
    if (glowa != NULL)
    {
        wypisz_rekurencyjnie_przedmioty_od_konca(glowa->nast);
        printf("%s %s %s\n", glowa->kod_przedmiotu, glowa->nazwa, glowa->semestr);
    }
}

void wypisz_rekurencyjnie_przedmioty(przedmiot *glowa)
{
    if (glowa != NULL)
    {
        printf("%s %s %s\n", glowa->kod_przedmiotu, glowa->nazwa, glowa->semestr);
        wypisz_rekurencyjnie_przedmioty_od_konca(glowa->nast);
    }
}

void wypisz_rekurencyjnie_oceny(ocena *glowa)
{
    if (glowa != NULL)
    {
        printf("%s  %s %f  %s\n", glowa->nr_albumu, glowa->kod, glowa->liczba, glowa->kometarz);
        wypisz_rekurencyjnie_oceny(glowa->nast);
    }
}

student *najwiekszy(student *glowa)
{
    student *max = NULL;
    while (glowa != NULL)
    {
        if (max == NULL)
        {
            max = glowa;
        }
        else
        {
            if (strcmp(glowa->nazwisko, max->nazwisko) > 0)
                max = glowa;
        }
        glowa = glowa->nast;
    }
    return max;
}

student *najmniejszy(student *glowa)
{
    student *min = NULL;
    while (glowa != NULL)
    {
        if (min == NULL)
        {
            min = glowa;
        }
        else
        {
            if (strcmp(glowa->nazwisko, min->nazwisko) < 0)
                min = glowa;
        }
        glowa = glowa->nast;
    }
    return min;
}

student *usun(student *glowa, student *el)
{
    student *c = glowa;
    if (glowa == el)
    {
        glowa = glowa->nast;
    }
    else
    {
        while (c != NULL)
        {
            if (c == el)
            {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;

                break;
            }

            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}

student *sortuj_przez_wybieranie_najwiekszy(student *glowa)
{
    student *nglowa = NULL;
    student *m;
    student *o; // = NULL;

    while (glowa != NULL)
    {
        m = najwiekszy(glowa);
        glowa = usun(glowa, m);

        o = ostatni(nglowa);
        if (o == NULL)
        {
            nglowa = m;
        }
        else
        {
            o->nast = m;
            m->poprz = o;
        }

        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}

student *sortuj_przez_wybieranie_najmniejszy(student *glowa)
{
    student *nglowa = NULL;
    student *m;
    student *o;

    while (glowa != NULL)
    {
        m = najmniejszy(glowa);
        glowa = usun(glowa, m);

        o = ostatni(nglowa);
        if (o == NULL)
        {
            nglowa = m;
        }
        else
        {
            o->nast = m;
            m->poprz = o;
        }
    }

    return nglowa;
}

przedmiot *ostatni_przedmiot(przedmiot *glowa)
{
    if (glowa != NULL)
    {
        while (glowa->nast != NULL)
            glowa = glowa->nast;
        return glowa;
    }
    else
    {
        return NULL;
    }
}

ocena *ostatnia_ocena(ocena *glowa)
{
    if (glowa != NULL)
    {
        while (glowa->nast != NULL)
            glowa = glowa->nast;
        return glowa;
    }
    else
    {
        return NULL;
    }
}

przedmiot *usun_przedmiot(przedmiot *glowa, przedmiot *el)
{
    przedmiot *c = glowa;
    if (glowa == el)
    {
        glowa = glowa->nast;
    }
    else
    {
        while (c != NULL)
        {
            if (c == el)
            {
                c->poprz->nast = c->nast;
                if (c->nast != NULL)
                    c->nast->poprz = c->poprz;

                break;
            }

            c = c->nast;
        }
    }
    c->nast = NULL;
    c->poprz = NULL;
    return glowa;
}

przedmiot *najmniejszy_przedmiot(przedmiot *glowa)
{
    przedmiot *min = NULL;
    while (glowa != NULL)
    {
        if (min == NULL)
        {
            min = glowa;
        }
        else
        {
            if (strcmp(glowa->kod_przedmiotu, min->kod_przedmiotu) > 0)
                min = glowa;
        }
        glowa = glowa->nast;
    }
    return min;
}

przedmiot *najmniejszy_przed_nazw(przedmiot *el)
{
    przedmiot *min = NULL;
    while (el != NULL)
    {
        if (min == NULL)
        {
            min = el;
        }
        else
        {
            if (strcmp(el->nazwa, min->nazwa) > 0)
                min = el;
        }
        el = el->nast;
    }
    return min;
}

przedmiot *sortuj_przez_wybieranie_najmniejszy_przed(przedmiot *glowa)
{
    przedmiot *nglowa = NULL;
    przedmiot *m;
    przedmiot *o; // = NULL;

    while (glowa != NULL)
    {
        m = najmniejszy_przedmiot(glowa);
        glowa = usun_przedmiot(glowa, m);

        o = ostatni_przedmiot(nglowa);
        if (o == NULL)
        {
            nglowa = m;
        }
        else
        {
            o->nast = m;
            m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}

przedmiot *sortuj_przed_przez_wybieranie_ros_nazw(przedmiot *glowa)
{
    przedmiot *nglowa = NULL;
    przedmiot *m;
    przedmiot *o; // = NULL;

    while (glowa != NULL)
    {
        m = najmniejszy_przed_nazw(glowa);
        glowa = usun_przedmiot(glowa, m);

        o = ostatni_przedmiot(nglowa);
        if (o == NULL)
        {
            nglowa = m;
        }
        else
        {
            o->nast = m;
            m->poprz = o;
        }
    }

    return nglowa;
}

// przedmiot *sortuj_przez_wybieranie_najmniejszy_przed_nazwa(przedmiot *glowa)
// {
//     przedmiot *nglowa = NULL;
//     przedmiot *m;
//     przedmiot *o; // = NULL;

//     while (glowa != NULL)
//     {
//         m = najmniejszy_przedmiot_nazwa(glowa);
//         glowa = usun_przedmiot(glowa, m);

//         o = ostatni_przedmiot(nglowa);
//         if (o == NULL)
//         {
//             nglowa = m;
//         }
//         else
//         {
//             o->nast = m;
//             m->poprz = o;
//         }
// o = m;

// printf("Najwiekszy: %s\n", m->nazwisko);
// wypisz_rekurencyjnie(glowa);
//     }

//     return nglowa;
// }

ocena *filtruj_przedmiot(ocena *glowa, char *kod_przedmiotu)
{
    ocena *nowa_glowa = NULL;
    ocena *m = NULL;

    while (glowa != NULL)
    {
        if (strcmp(glowa->kod, kod_przedmiotu) == 0)
        {
            ocena *o = (ocena *)malloc(sizeof(ocena));
            o->nast = NULL;
            o->poprz = NULL;
            if (nowa_glowa == NULL){
            nowa_glowa = o;
            }
            else
            {
                m = ostatnia_ocena(nowa_glowa);
                m->nast = o;
                o->poprz = m;
            }
            nowa_glowa->nr_albumu = glowa->nr_albumu;
            nowa_glowa->kod = glowa->kod;
            nowa_glowa->liczba = glowa->liczba;
            nowa_glowa->kometarz = glowa->kometarz;
            printf("%s %s %f %s", nowa_glowa->kod, nowa_glowa->nr_albumu, nowa_glowa->liczba, nowa_glowa->kometarz);

            
        } glowa= glowa->nast;
    }return nowa_glowa;
}
    student *wczytaj_studentow(FILE * fin)
    {
        char bufor[255];
        int n, i;
        char *s;
        //student *last_student = NULL;
        student *glowa = NULL;
        fgets(bufor, 254, fin);
        sscanf(bufor, "%d", &n);

        for (i = 0; i < n; i++)
        {

            student *stud = (student *)malloc(sizeof(student));
            stud->nast = NULL;
            stud->poprz = NULL;
            student *c;

            if (glowa == NULL)
                glowa = stud;
            else
            {
                c = ostatni(glowa);
                c->nast = stud;
                stud->poprz = c;
            }

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

    przedmiot *wczytaj_przedmiot(FILE * fin)
    {
        char bufor[255];
        int n, i;
        char *s;
        //przedmiot *last_przedmiot = NULL;
        przedmiot *glowa = NULL;
        fgets(bufor, 254, fin);
        sscanf(bufor, "%d", &n);

        for (i = 0; i < n; i++)
        {

            przedmiot *przed = (przedmiot *)malloc(sizeof(przedmiot));
            przed->nast = NULL;
            przed->poprz = NULL;
            przedmiot *c;

            if (glowa == NULL)
                glowa = przed;
            else
            {
                c = ostatni_przedmiot(glowa);
                c->nast = przed;
                przed->poprz = c;
            }

            fgets(bufor, 254, fin);
            s = strtok(bufor, ";");
            przed->kod_przedmiotu = (char *)malloc(sizeof(char) * (strlen(s) + 1));
            strcpy(przed->kod_przedmiotu, s);

            s = strtok(NULL, ";");
            przed->nazwa = (char *)malloc(sizeof(char) * (strlen(s) + 1));
            strcpy(przed->nazwa, s);

            s = strtok(NULL, "\n");
            przed->semestr = (char *)malloc(sizeof(char) * (strlen(s) + 1));
            strcpy(przed->semestr, s);
        }

        return glowa;
    }

    ocena *wczytaj_ocene(FILE * fin)
    {

        char bufor[255];
        int n, i;
        char *s;
        //ocena *last_ocena = NULL;
        ocena *glowa = NULL;
        fgets(bufor, 254, fin);
        sscanf(bufor, "%d", &n);

        for (i = 0; i < n; i++)
        {

            ocena *_ocena = (ocena *)malloc(sizeof(ocena));
            _ocena->nast = NULL;
            _ocena->poprz = NULL;
            ocena *c;

            if (glowa == NULL)
                glowa = _ocena;
            else{
                c = ostatnia_ocena(glowa);
                c->nast = _ocena;
                _ocena->poprz = c;
            }

            fgets(bufor, 254, fin);
            s = strtok(bufor, ";");
            _ocena->nr_albumu = (char *)malloc(sizeof(char) * (strlen(s) + 1));
            strcpy(_ocena->nr_albumu, s);

            s = strtok(NULL, ";");
            _ocena->kod = (char *)malloc(sizeof(char) * (strlen(s) + 1));
            strcpy(_ocena->kod, s);

            s = strtok(NULL, ";");
            _ocena->liczba = atof(s);

            s = strtok(NULL, "\n");
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

    int ile_studentow(sbaza * baza)
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

    int ile_przedmiotow(sbaza * baza)
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

    int ile_ocen(sbaza * baza)
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

        return NULL;
    }

    void listuj_studentow(sbaza * baza)
    {
        
        wypisz_rekurencyjnie_studentow(baza->lista_studentow);
    }

    void listuj_przedmioty(sbaza * baza)
    {
        wypisz_rekurencyjnie_przedmioty_od_konca(baza->lista_przedmiotow);
    }
    void listuj_oceny(sbaza * baza)
    {
        wypisz_rekurencyjnie_oceny(baza->lista_ocen);
    }

    void dodaj_studentow(sbaza * baza, char *imie, char *nazwisko, char *nr_albumu, char *email)
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

    void dodaj_przedmiot(sbaza * baza, char *kod_przedmiotu, char *nazwa, char *semestr)
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

    void dodaj_studenta_do_przed(sbaza * baza, char *nr_albumu, char *kod, float liczba, char *kometarz)
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

    void zwolnij_student(student * s)
    {
        free(s->imie);
        free(s->nazwisko);
        free(s->nr_albumu);
        free(s->email);
        free(s);
    }

    void zwolnij_przedmiot(przedmiot * s)
    {
        free(s->kod_przedmiotu);
        free(s->nazwa);
        free(s->semestr);
        free(s);
    }

    void zwolnij_ocena(ocena * s)
    {
        free(s->nr_albumu);
        free(s->kod);
        free(s->kometarz);
        free(s);
    }

    void zwolnij_liste_studentow(student * s)
    {
        student *n;
        while (s != NULL)
        {
            n = s->nast;
            zwolnij_student(s);
            s = n;
        }
    }

    void zwolnij_liste_przedmiotow(przedmiot * s)
    {
        przedmiot *n;
        while (s != NULL)
        {
            n = s->nast;
            zwolnij_przedmiot(s);
            s = n;
        }
    }

    void zwolnij_liste_ocen(ocena * s)
    {
        ocena *n;
        while (s != NULL)
        {
            n = s->nast;
            zwolnij_ocena(s);
            s = n;
        }
    }

    void zwolnij(sbaza * baza)
    {
        zwolnij_liste_studentow(baza->lista_studentow);
        zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
        zwolnij_liste_ocen(baza->lista_ocen);
        free(baza);
    }