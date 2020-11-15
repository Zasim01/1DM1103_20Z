#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student;

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

//wczytywanie działa-sprawdzone

int znajdz(char *szukany_kod, char kod_przedmiotow[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_kod, kod_przedmiotow[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_kody_przed(char kod_przedmiotow[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].kod_przed, kod_przedmiotow, ile_znalazlem ) == -1) {
            strncpy(kod_przedmiotow[ile_znalazlem], dane[i].kod_przed, 9);
            ile_znalazlem++;
        }
    }printf("%s",kod_przedmiotow[i] );
    return ile_znalazlem;
}


void srednia(student dane[100], int ile_rekordow) {
    char kod_przedmiotow[100][10];
    char nazwy_przed [100][225];
    int ile_przedmiotow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100]; 
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;
    int najgorsza_srednia;
    float najgorsza = 6.0f;

    ile_przedmiotow = znajdz_kody_przed(kod_przedmiotow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, kod_przedmiotow, ile_przedmiotow );
        strcpy(nazwy_przed[pozycja], dane[i].nazwa_przed);
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepsza średnia: %s - %s: %f", 
        nazwy_przed[najlepsza_pozycja],kod_przedmiotow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]);

    printf("\n");

    for (i=0; i < ile_przedmiotow; i++) {
        if (najgorsza > sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najgorsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najgorsza_srednia = i;
        }
    }   printf("Najgorsza średnia: %s - %s: %f", 
        nazwy_przed[najgorsza_srednia],kod_przedmiotow[najgorsza_srednia],
        sumy_wazonych_ocen[najgorsza_srednia] / sumy_ects[najgorsza_srednia]);

}

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);
    srednia(dane,ile);

    return 0;
}