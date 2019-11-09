all: primefactorization

primefactorization: primefactorization.o
	gcc primefactorization.o -o primefactorization

primefactorization.o: primefactorization.c
	gcc -c primefactorization.c

clean:
	rm -r primefactorization *o