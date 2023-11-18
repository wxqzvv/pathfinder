#include "../inc/pathfinder.h"

int GetSizeFromFile(char *str) {
    int size;
    char **strArr = mx_strsplit(str, '\n');

    size = mx_atoi(strArr[0]);

    mx_del_strarr(&strArr);

    return size;
}
