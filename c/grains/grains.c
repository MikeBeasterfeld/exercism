#include "grains.h"
#include <math.h>


uint64_t square(uint8_t index) {
    if (index < 1 || index > 64) return 0;
    if (index == 1) return 1;

    return pow(2, index - 1);
}

uint64_t total(void) {
    int sum = 0;
    for(int i = 1; i <= 64; i++) {
        sum += square(i);
    }
    return sum;
}