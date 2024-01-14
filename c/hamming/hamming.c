#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    if (strlen(lhs) != strlen(rhs)) return -1;

    int difference_count = 0;

    for(int i = 0; i < (int) strlen(lhs); i++) {
        if(lhs[i] != rhs[i]) difference_count++;
    }

    return difference_count;
}