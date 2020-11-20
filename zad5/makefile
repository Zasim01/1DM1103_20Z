
DEPS=main.o studenci.o dziekanat.o #studenci.h dziekanat.h

main:$(DEPS)
	cc $^ -o $@ -Wall --pedantic


%.o:%.c
	cc -c $^ -o $@

clean:
	rm main
	rm *.o

#co_chcemy_zrobic:od_czego_to_zalezy
#(TAB)co_trzeba_uruchomic_aby_uzyskac_co