#include <stdbool.h>
#include <stdio.h>

// macro para obtener un natural por la entrada estándar,
// bastante más rápido que scanf
#define fscanu(x)                                                              \
    do {                                                                       \
	char _;                                                                \
	while ((x = getchar_unlocked()) < '0')                                 \
	    ;                                                                  \
	x -= '0';                                                              \
	while ('0' <= (_ = getchar_unlocked())) {                              \
	    x = (x << 3) + (x << 1) + _ - '0';                                 \
	}                                                                      \
    } while (0);

int main(void) {
    unsigned int casos;
    bool inc, dec;
    unsigned long long int prev, cur;

L1:
    fscanu(casos);

    if (!casos)
	return 0;

    fscanu(prev);
    inc = true;
    dec = true;

    while (--casos) {
	fscanu(cur);

	inc = inc && prev < cur;
	dec = dec && prev > cur;

	if (!inc && !dec) {
	    puts("DESCONOCIDOS");
	    while (--casos) {
		getchar_unlocked();
		while (getchar_unlocked() >= '0')
		    ;
	    }
	    goto L1;
	}

	prev = cur;
    }

    puts("DALTON");
    goto L1;
}
