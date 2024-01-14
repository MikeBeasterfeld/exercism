#include "armstrong_numbers.h"
#include <stdio.h>

bool is_armstrong_number(int num) {
    int sum = 0;
    int count = 0;

    for (int i = num; i > 0; i /= 10) {
        count++;
    }

    for (int i = num; i > 0; i /= 10) {
        int digit = i % 10;
        int exponential = digit;
        
        for (int j = 1; j < count; j++) {
            exponential *= digit;
        }

        sum += exponential;
    }

    return sum == num;
}