#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex){
    if (hex == NULL){
        return 0;
    }
    int j = 0;
    while (hex[j] != '\0'){
        j++;
    }
    unsigned long rs = 0;
    unsigned long dc = 1;;
    for (int i = j - 1; i >=0; i--){
        if (hex[i] >= '0' && hex[i] <= '9'){
            rs += ((hex[i] - 48) * dc);
            dc *= 16;
        }   
        if(hex[i] >= 'A' && hex[i]  <= 'z'){
            if(hex[i] >= 'A' && hex[i] <= 'Z'){
                rs += ((hex[i] - 55) * dc);
                dc *= 16;
            }
            else {
                rs += ((hex[i] - 87) * dc);
                dc *= 16;
            }
        }
    }
    return rs;
}
