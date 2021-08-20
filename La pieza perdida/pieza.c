#include <stdio.h>

#define fprintu(x)                                                             \
    do {                                                                       \
        unsigned N = (x);                                                      \
        unsigned rev = N;                                                      \
        unsigned count = 0;                                                    \
                                                                               \
        while ((rev % 10) == 0) {                                              \
            count++;                                                           \
            rev /= 10;                                                         \
        }                                                                      \
        rev = 0;                                                               \
        while (N != 0) {                                                       \
            rev = (rev << 3) + (rev << 1) + N % 10;                            \
            N /= 10;                                                           \
        }                                                                      \
        while (rev != 0) {                                                     \
            putchar_unlocked(rev % 10 + '0');                                  \
            rev /= 10;                                                         \
        }                                                                      \
        while (count--)                                                        \
            putchar_unlocked('0');                                             \
    } while (0)

int main(void) {
    unsigned int pieces, sum, tmp, i;
    char _;

    while (1) {
        if ((_ = getchar_unlocked()) == '0')
            return 0;

        for (pieces = _ - '0'; '0' <= (_ = getchar_unlocked());)
            pieces = (pieces << 3) + (pieces << 1) + _ - '0';

        sum = 0;

        for (i = 0; i < pieces - 1; ++i) {
            for (tmp = getchar_unlocked() - '0';
                 '0' <= (_ = getchar_unlocked());)
                tmp = (tmp << 3) + (tmp << 1) + _ - '0';

            sum += tmp;
        }

        fprintu(((pieces * (pieces + 1)) / 2) - sum);
        putchar_unlocked('\n');
    }
}
