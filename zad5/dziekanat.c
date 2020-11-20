#include "dziekanat.h"

void najlepszy_student(student dane[100], int ile_rekordow)
{
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100] = {0};
    int sumy_ects[100]= {0};
    //float srednie[100] ;
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    for (i=0;i<ile_studentow; i++) 
       // printf("Student [%d]: %s - %f:%d \n", i+1, nr_albumow[i], 
        //sumy_wazonych_ocen[i], sumy_ects[i]);

    for(i=0; i<ile_studentow; i++)
    {
        if (najlepsza<sumy_wazonych_ocen[i]/sumy_ects[i])
        {
            najlepsza = sumy_wazonych_ocen[i]/sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }
    printf("Najlepszy student: [%d] : %s - %f\n", najlepsza_pozycja+1
    , nr_albumow[najlepsza_pozycja],sumy_wazonych_ocen[najlepsza_pozycja]/sumy_ects[najlepsza_pozycja]);
}


void srednia(student dane[100], int ile_rekordow) {
    char kod_przedmiotow[100][10];
    char nazwy_przed [100][225];
    int ile_przedmiotow;
    float sumy_wazonych_ocen[100] = {0};
    int sumy_ects[100] = {0}; 
    //float srednie[100] = {0};
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;
    int najgorsza_srednia;
    float najgorsza = 6.0f;

    ile_przedmiotow = znajdz_kody_przed(kod_przedmiotow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz_przedmiot( dane[i].kod_przed, kod_przedmiotow, ile_przedmiotow );
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