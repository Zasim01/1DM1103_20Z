all: 
	cc baza.c main.c -o mydb -Wall --pedantic

test:
	./mydb baza.csv list_students

test-od-konca:
	./mydb baza.csv list_students_from_end

test-ile:
	./mydb baza.csv count_students

test-sortuj-malejaco:
	./mydb baza.csv sort_descending

test-sortuj-wzrastajaco:
	./mydb baza.csv sort_ascending


test-sortuj-przedmioty-pokodzie:
	valgrind -s ./mydb baza.csv sort_subjects_ascending

test-sortuj-przedmioty-ponazwie:
	./mydb baza.csv sort_subjects_ascending_name

test-5:
	./mydb baza.csv znajdz_oceny_z_kodu





test-test:
	./mydb baza.csv sprawdzenie_co_wyszlo





test-memory:
	valgrind ./mydb baza.csv count_students

test-dodaj:
	valgrind ./mydb baza.csv add_student  Alicja Wiśniewska 00009 bu@bu.pl

test-przedmiot:
	valgrind ./mydb baza.csv add_subject  1DA1245 Matematyka 2020Z

test-ocena:
	valgrind ./mydb baza.csv add_grade  1DE2103 00009 5 buuu



	