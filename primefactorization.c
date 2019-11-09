#include <stdio.h>
#include <stdlib.h>

int main() {
  // program for factoring a number into its base primes
  // can then use this and the formula (a1 + 1) * (a2 + 1) * ... to find
  // total number of factors for that number (numberphile 5040 video)

  // goto method creates chart of auto-generated factorizations
  // two other implementations - array and pointer inputs

  // optimize by prefactoring?? i.e. 90 -> 9 x 10 -> 2 x 3^2 x 5
  // see factoropt.c
  int primes[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
		    53, 59, 61, 67, 71};
  int factors[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  int *primesPtr;
  int numPrevPrimes = 20;
  char primesRealloc = 0;
  int *factorsPtr;
  int numFactors = 1;
  char factorsRealloc = 0;

  primesPtr = calloc(numPrevPrimes, sizeof(primesPtr[0]));
  factorsPtr = calloc(numFactors, sizeof(factorsPtr[0]));

  int tbfcopy, tbf = 2;
  int tot;
  int i, j, k;

  char ins[10];
  char *s;

  // could easily do a function instead of a goto but i put this in
  // at the end cause im lazy
  START: // comment out if not using goto method
  // after start: label, must come statement, not declaration

  tbfcopy = tbf;

  //  s = (char *) malloc(10);
  //  if (!s) return 1; // malloc returns NULL on failure, can not store input

  // printf("Enter a number to be prime-factored: ");
  // fgets(ins, 10, stdin);
  //  fgets(s, 10, stdin);
  // tbfcopy = atoi(ins);
  //  tbfcopy = atoi(s);

  //  free(s);

  k = 0;
  i = 0;
  j = 0;
  tot = 1;

  // reset to 0
  while (factors[k]) {
    factors[k++] = 0;
  }
  if (factorsRealloc == 1) {
    factorsPtr = realloc(factorsPtr, numFactors * sizeof(factorsPtr[0]));
  }

  // populate list of primes
  if (primesRealloc == 1) {
    primesPtr = realloc(primesPtr, numPrevPrimes * sizeof(primesPtr[0]));
  }

  // find factors
  while (tbfcopy != 1 && i < (sizeof(primes)/sizeof(primes[0]))) {
    if (tbfcopy % primes[i] == 0) {
      tbfcopy /= primes[i];
      factors[j++] = primes[i];
    }
    else i++;
  }

  // debug checkpoint
  //  int ctr = 0;
  //  while (factors[ctr]) printf("%d ", factors[ctr++]);
  //  printf("\n%d %d %d %d\n(Stop 1) Enter to continue: ", i, j, k, tbfcopy);
  //  int input = 0;
  //  while (input != 10) { // investigate this loop in detail later
  //    input = getchar();
  //    //printf("%d\n", input);
  //  }

  // output
  printf("%d:\t", tbf);

  //  int n = numFactors;
  int n = sizeof(factors) / sizeof(factors[0]);
  for (i = 0; i < j; i++) {
    // if it's the last factor to display
    if (i + 1 == n || i + 1 == j) {
      printf("%d", factors[i]); // j !> n?
      tot *= 2;
    }
    // if the factor is unique -- only appears once
    else if (factors[i + 1] != factors[i]) {
      printf("%d \u00d7 ", factors[i]);
      tot *= 2;
    }
    // if the factor appears two or more times in the prime factorization
    else {
      int exp = 1;
      // determine how many times the factor appears
      while (factors[i + 1] == factors[i] && i++ < n) {
	exp++;
      }
      tot *= exp + 1;

      printf("%d", factors[i - 1]);
      // so it looks nice, print exponent
      switch(exp) {
      case 2:
        printf("\u00b2");
	break;
      case 3:
	printf("\u00b3");
	break;
      case 4:
	printf("\u2074");
	break;
      case 5:
	printf("\u2075");
	break;
      case 6:
	printf("\u2076");
	break;
      case 7:
	printf("\u2077");
	break;
      case 8:
	printf("\u2078");
	break;
      case 9:
	printf("\u2079");
	break;
      }
      // add multiplication sign if necessary
      if (factors[i + 1] != 0) printf(" \u00d7 ");
    }
  }

  // debug checkpoint
  //  printf("%d %d %d %d\n(Stop 2) Enter to continue: ", i, j, k, tbfcopy);
  //  input = 0;
  //  while (input != 10) { // investigate this loop in detail later
  //    input = getchar();
  //    //printf("%d\n", input);
  //  }

  // verifies
  //  k = 0;
  //  int tempprod = 1;
  //  while (factors[k]) {
  //    tempprod *= factors[k++];
  //  }
  //  fputs("\t\t", stdout);
  //  fputs((tempprod == tbf) ? "true" : "false", stdout);

  // could look nicer with ncurses for auto-generated method
  // i can't remember what tot is supposed to be tracking
  printf(":\t%d\n", tot);

  // lists all prime factorizations from 2 to 60
  if (tbf++ < 60) goto START; // comment out unless using table method

  free(factorsPtr);
  free(primesPtr);

  return 0;
}
