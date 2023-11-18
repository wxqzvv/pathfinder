#include "../inc/pathfinder.h"

int GetIndex(char **strarr, char *str) {
    for (int i = 0; strarr[i] != NULL; i++) {
        if (mx_strcmp(strarr[i], str) == 0) {
            return i;
        }
    }
    return -1;
}
