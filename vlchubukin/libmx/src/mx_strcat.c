#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2)
{
    int s1Len = mx_strlen(s1);
    int s2Len = mx_strlen(s2);

    for (int i = s1Len, q = 0; q < s2Len + 1; i++, q++)
    {
        s1[i] = s2[q];
    }

    return s1;
}
