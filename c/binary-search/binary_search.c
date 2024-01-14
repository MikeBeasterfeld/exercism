#include "binary_search.h"
#include <stdbool.h>
#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length) {
    int* addr = NULL;
    size_t half = length / 2;
    size_t minimum = 0;
    size_t maximum = length;
    int max_loops = 0;

    // print("length %lu\n", length);
    // print("value %i\n", value);

    while(length > 0) {
        max_loops++;
        // print("halfway %lu - value %i\n", half, arr[half]);

        if (arr[half] == value) {
            return &arr[half];
        }

        // 1, 2, 3, 4, 5, 6, 7, 8, 9
        // 5
        // 5, 6, 7, 8, 9
        // 7 = half + ((max - half) / 2) + ((max - half) % 2)

        // 1, 3, 4, 6, 8, 9, 11

        if (arr[half] < value) {
            // print("Larger\n");
            minimum = half + 1;
            half = ((maximum - minimum) / 2) + minimum;
        }

        // 1, 2, 3, 4, 5, 6, 7, 8, 9
        // 5
        // 5, 6, 7, 8, 9
        // 3 = min + ((half - min) / 2) + ((half - min) % 2)

        // 1, 3, 4, 6, 8, 9, 11 

        if (arr[half] > value) {
            // print("Smaller\n");
            if (half == 0) break;
            maximum = half - 1;
            half = ((maximum - minimum) / 2) - 1;
        }

        if (maximum == minimum) {
            half = maximum;
        }

        // print("Maximum %lu\n", maximum);
        // print("Minimum %lu\n", minimum);

        // print("Next half %lu\n", half);

        if (minimum > maximum) {
            // print("Not found\n");
            break;
        }

        if (max_loops > 20) break;

    }

    return addr;
}
