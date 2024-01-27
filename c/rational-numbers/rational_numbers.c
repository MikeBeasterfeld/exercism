#include <stdio.h>
#include <math.h>
#include "rational_numbers.h"

void print(rational_t arg1) {
    printf("%i/%i\n", arg1.numerator, arg1.denominator);
}

rational_t reduce(rational_t arg1) {
    print(arg1);

    if (arg1.numerator == 0) {
        rational_t zero = {0, 1};
        return zero;
    }

    if (arg1.denominator < 0) {
        arg1.numerator *= -1;
        arg1.denominator *= -1;
    }

    if ((arg1.numerator > 1 || arg1.numerator < -1) && arg1.denominator % arg1.numerator == 0) {
        int numerator = arg1.numerator;
        if (numerator < 0) {
            numerator *= -1;
        }
        arg1.numerator = arg1.numerator / numerator;
        arg1.denominator = arg1.denominator / numerator;
    }

        if (arg1.denominator > 1 && arg1.numerator % arg1.denominator == 0) {
        int divisor = arg1.denominator;
        arg1.numerator = arg1.numerator / divisor;
        arg1.denominator = arg1.denominator / divisor;
    }

    if ((arg1.numerator > 1 || arg1.numerator < -1) && arg1.denominator % 2 == 0 && arg1.numerator % 2 == 0) {
        int divisor = 2;
        arg1.numerator = arg1.numerator / divisor;
        arg1.denominator = arg1.denominator / divisor;
    }

    if ((arg1.numerator > 1 || arg1.numerator < -1) && arg1.denominator % 3 == 0 && arg1.numerator % 3 == 0) {
        int divisor = 3;
        arg1.numerator = arg1.numerator / divisor;
        arg1.denominator = arg1.denominator / divisor;
    }

    print(arg1);

    return arg1;
}

rational_t add(rational_t arg1, rational_t arg2) {
    rational_t result = {
        arg1.numerator * arg2.denominator + arg2.numerator * arg1.denominator,
        arg1.denominator * arg2.denominator
    };

    print(result);

    return reduce(result);
}

rational_t subtract(rational_t arg1, rational_t arg2) {
    rational_t result = {
        arg1.numerator * arg2.denominator - arg2.numerator * arg1.denominator,
        arg1.denominator * arg2.denominator
    };

    print(result);

    return reduce(result);
}

rational_t multiply(rational_t arg1, rational_t arg2) {
    rational_t result = {
        arg1.numerator * arg2.numerator,
        arg1.denominator * arg2.denominator
    };

    print(result);

    return reduce(result);
}

rational_t divide(rational_t arg1, rational_t arg2) {
    rational_t result = {
        arg1.numerator * arg2.denominator,
        arg2.numerator * arg1.denominator
    };

    print(result);

    return reduce(result);
}

rational_t absolute(rational_t arg1) {
    rational_t result = arg1;

    if (result.numerator < 0) {
        result.numerator *= -1;
    }

    if (result.denominator < 0) {
        result.denominator *= -1;
    }

    print(reduce(result));

    return reduce(result);
}

rational_t exp_rational(rational_t arg1, int power) {
    rational_t result = {
        1,1
    };

    if (power > 0) {
        result.numerator = pow(arg1.numerator, power);
        result.denominator = pow(arg1.denominator, power);
    }

    if (power < 0) {
        result.numerator = pow(arg1.denominator, power * -1);
        result.denominator = pow(arg1.numerator, power * -1);
    }


    print(reduce(result));

    return reduce(result);
}

float exp_real(uint16_t x, rational_t r) {
    float power = (float) r.numerator / (float) r.denominator;
    printf("%.6f\n", power);
    return pow(x, power);
}

// rational_t reduce(rational_t arg1) {
//     rational_t result = {
//         arg1.numerator,
//         arg1.denominator
//     };

//     printf("Reduce? %i\n", arg1.denominator % arg1.numerator);

//     if ((arg1.numerator > 1 || arg1.numerator < -1) && arg1.denominator % arg1.numerator == 0) {
//         printf("Yes reduce\n");
//         int numerator = arg1.numerator;
//         if (numerator < 0) {
//             numerator *= -1;
//         }
//         result.numerator = arg1.numerator / numerator;
//         result.denominator = arg1.denominator / numerator;
//         print(result);
//     }

//     return result;
// }
