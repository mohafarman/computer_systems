#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// We can store no more than 6 bytes in a double precision float pointer
// IEEE 754
#define LENGTH 6

double conceal(char *s) {
    double nan = NAN;
    uint64_t *p = (uint64_t *)&nan;
    uint64_t bits = *p;
    uint64_t msg = bits;
    for (int i = 0; i < LENGTH; i++)
        msg |= (uint64_t)s[i] << 8 * i;
    return *(double *)&msg;
}

char *extract(double msg_conc) {
    char *msg = malloc(sizeof(LENGTH));
    uint64_t *p = (uint64_t *)&msg_conc;
    uint64_t bits = *p;
    for (int i = 0; i < LENGTH; i++) {
        msg[i] = (char)((bits >> 8 * i) & 0xFF);
    }
    return msg;
}

int main(int argc, char *argv[]) {
    (void)argc, (void)argv;

    char *s = "hello!kindSir!";
    printf("%s\n", s);

    double msg_conc = conceal(s);

    msg_conc = msg_conc * 2;
    msg_conc = msg_conc / 10;

    char *msg_extr = extract(msg_conc);

    printf("%s\n", msg_extr);
    return 0;
}
