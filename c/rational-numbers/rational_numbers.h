#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

typedef struct {
    int numerator;
    int denominator;
} rational_t;

#endif

#include <stdint.h>

void print(rational_t arg1);

rational_t reduce(rational_t arg1);

rational_t add(rational_t arg1, rational_t arg2);
rational_t subtract(rational_t arg1, rational_t arg2);
rational_t multiply(rational_t arg1, rational_t arg2);
rational_t divide(rational_t arg1, rational_t arg2);

rational_t absolute(rational_t arg1);
rational_t exp_rational(rational_t arg1, int pow);

rational_t reduce(rational_t arg1);

float exp_real(uint16_t x, rational_t r);
