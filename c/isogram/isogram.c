#include "isogram.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool is_isogram(const char phrase[]) {
    if(phrase == NULL) return false;
    
    int length = strlen_s(phrase);
    
    for(int i = 0; i < length; i++) {
        if (phrase[i] != '-' && phrase[i] != ' ') {
            for(int j = i + 1; j < length; j++) {
                if(tolower(phrase[i]) == tolower(phrase[j])) {
                    return false;
                }
            }
        }
    }
    return true;
}