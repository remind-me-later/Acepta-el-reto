#include <stdio.h>

// macro para obtener un natural por la entrada estándar,
// bastante más rápido que scanf
#define get_unsigned(x)                                                        \
    do {                                                                       \
	char _;                                                                \
	while ((_ = getchar_unlocked()) < '0')                                 \
	    ;                                                                  \
	x = _ - '0';                                                           \
	while ('0' <= (_ = getchar_unlocked())) {                              \
	    x = (x << 3) + (x << 1) + _ - '0';                                 \
	}                                                                      \
	if (_ == '-')                                                          \
	    return 0;                                                          \
    } while (0);

#define print_unsigned(x)                                                      \
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
    int Ax, Ay;
    int Bx, By;
    int b, h;

    while (1) {
	get_unsigned(Ax);
	get_unsigned(Ay);
	get_unsigned(Bx);
	get_unsigned(By);

	b = Bx - Ax;
	h = By - Ay;

	if (b < 0 || h < 0)
	    return 0;

	print_unsigned(b * h);
	putchar_unlocked('\n');
    }
}
