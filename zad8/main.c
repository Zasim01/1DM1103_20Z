#include <stdio.h>
#include <stdlib.h>

#include "baza.h"
int main(int argc, char**argv)
{
    sbaza*baza;
    baza = wczytaj_baze(argv[1]);

    if(strcmp("list_students", argv[2])==0 )
    {
        listuj_studentow(baza);
    }
    else if (strcmp("list_students_from_end", argv[2])==0 )
    {
        
        listuj_studentow_od_konca(baza);

    }
    else if (strcmp("sort_descending", argv[2]) == 0) {
        baza->lista_studentow = sortuj_przez_wybieranie_najwiekszy(baza->lista_studentow); 
        listuj_studentow(baza);
    }
    else if (strcmp("sort_ascending", argv[2]) == 0) {
        baza->lista_studentow = sortuj_przez_wybieranie_najmniejszy(baza->lista_studentow); 
        listuj_studentow(baza);
    }
    else if (strcmp("sort_subjects_ascending", argv[2]) == 0) {
        baza->lista_przedmiotow = sortuj_przez_wybieranie_najmniejszy_przed(baza->lista_przedmiotow); 
        listuj_przedmioty(baza);
    
    }
     else if (strcmp("sort_subjects_ascending_name", argv[2]) == 0) {
        baza->lista_przedmiotow = sortuj_przed_przez_wybieranie_ros_nazw(baza->lista_przedmiotow); 
        listuj_przedmioty(baza);
    
    }

    else if (strcmp("znajdz_oceny_z_kodu", argv[2]) == 0) {
        ocena*glowa;
        glowa = filtruj_przedmiot(baza->lista_ocen,"1DE2103"); 
        while(glowa != NULL){
            printf("%f\n", glowa->liczba);
            printf("%f\n", glowa->nast ->liczba);

        }
        //listuj_oceny(baza);
    
    }


    // else if (strcmp("sprawdzenie_co_wyszlo", argv[2]) == 0) {
    //     baza->lista_przedmiotow = filtruj(baza->lista_przedmiotow, "1DE2103"); 

    //     listuj_przedmioty(baza);
    // }

    // else if (strcmp("punkt 5", argv[2]) == 0) {
    //     baza->lista_ocen = filtruj_ocene(baza->lista_ocen, "123456"); 
    //     wypisz_rekurencyjnie_oceny(baza);
    
    // }







    else if (strcmp("add_student", argv[2])==0 )
    {
        
        dodaj_studentow(baza,argv[3],argv[4],argv[5],argv[6]);

    }
    else if (strcmp("add_subject", argv[2])==0 )
    {
        dodaj_przedmiot(baza,argv[3],argv[4],argv[5]);

    }

    else if (strcmp("add_grade", argv[2])==0 )
    {
        dodaj_studenta_do_przed(baza,argv[3],argv[4],atof(argv[5]),argv[6]);

    }

    else if(strcmp("count_students", argv[2]) == 0)
    {
        printf("Liczba studentów to %d\n",ile_studentow(baza));
    }

    zapisz_baze(argv[1],baza);
    zwolnij(baza);
    return 0;
}