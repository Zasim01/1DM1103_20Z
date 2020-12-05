all: 
	cc baza.c main.c -o mydb -Wall --pedantic

test:
	./mydb baza.csv list_students

test_ile:
	./mydb baza.csv count_students

test-memory:
	valgrind ./mydb baza.csv count_students

test_dodaj:
	valgrind ./mydb baza.csv add_student  Alicja Wiśniewska 00009 bu@bu.pl

test_przedmiot:
	valgrind ./mydb baza.csv add_subject  1DA1245 Matematyka 2020Z

test_ocena:
	valgrind ./mydb baza.csv add_student  1DE2103 00009 5 buuu