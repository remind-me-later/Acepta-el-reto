#include <stdio.h>

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

#define fprintu(x)                                                             \
    do {                                                                       \
	if (x == 0) {                                                          \
	    putchar_unlocked('0');                                             \
	} else {                                                               \
	    unsigned N = (x);                                                  \
	    unsigned rev = N;                                                  \
	    unsigned count = 0;                                                \
                                                                               \
	    while ((rev % 10) == 0) {                                          \
		count++;                                                       \
		rev /= 10;                                                     \
	    }                                                                  \
	    rev = 0;                                                           \
	    while (N != 0) {                                                   \
		rev = (rev << 3) + (rev << 1) + N % 10;                        \
		N /= 10;                                                       \
	    }                                                                  \
	    while (rev != 0) {                                                 \
		putchar_unlocked(rev % 10 + '0');                              \
		rev /= 10;                                                     \
	    }                                                                  \
	    while (count--)                                                    \
		putchar_unlocked('0');                                         \
	}                                                                      \
    } while (0)

int main(void) {
    unsigned int casos;
    fscanu(casos);

    while (casos--) {
	unsigned int n;
	fscanu(n);
	fprintu(n / 3);
	putchar_unlocked('\n');
    }

    return 0;
}
