all: sudokusolver ncursestest primefactorization ncursestest2 ncursestest3 ncursestest4

sudokusolver: sudokusolver.o
	gcc sudokusolver.o -o sudokusolver

sudokusolver.o: sudokusolver.c
	gcc -c sudokusolver.c

primefactorization: primefactorization.o
	gcc primefactorization.o -o primefactorization

primefactorization.o: primefactorization.c
	gcc -c primefactorization.c

ncursestest: ncursestest.o
	gcc ncursestest.o -o ncursestest -lncurses

ncursestest.o: ncursestest.c
	gcc -c ncursestest.c

ncursestest2: ncursestest2.c
	gcc ncursestest2.c -o ncursestest2 -lncurses

ncursestest3: ncursestest3.c
	gcc ncursestest3.c -o ncursestest3 -lncurses

ncursestest4: ncursestest4.c
	gcc ncursestest4.c -o ncursestest4 -lncurses

clean:
	rm -r sudokusolver ncursestest primefactorization *o