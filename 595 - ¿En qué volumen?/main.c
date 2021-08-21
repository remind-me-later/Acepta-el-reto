#include <stdio.h>

#define scan(x)                                                                \
    do {                                                                       \
	char _;                                                                \
	while ((x = getchar_unlocked()) < '0')                                 \
	    ;                                                                  \
	for (x -= '0'; '0' <= (_ = getchar_unlocked());                        \
	     x = (x << 3) + (x << 1) + _ - '0')                                \
	    ;                                                                  \
    } while (0)

#define BUFFER_LEN 7

int main(void) {
    unsigned short N;
    unsigned char i, j;
    char line[BUFFER_LEN];

    scan(N);

    while (N--) {
	line[0] = getchar_unlocked();
	for (i = 1; line[i - 1] != '\n'; ++i)
	    line[i] = getchar_unlocked();

	for (j = 0; j < i - 3; ++j)
	    putchar_unlocked(line[j]);

	putchar_unlocked('\n');
    }

    return 0;
}
