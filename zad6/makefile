
DEPS=main.o operacje.o operacje_matematyczne.o 

main:$(DEPS)
	cc $^ -o $@ -lm -Wall --pedantic


%.o:%.c
	cc -c $^ -o $@

clean:
	rm main
	rm *.o
