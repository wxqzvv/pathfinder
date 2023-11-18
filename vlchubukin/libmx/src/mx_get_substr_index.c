#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub)
{
    if (!str || !sub)
    {
        return -2;
    }

    char *subString = mx_strstr(str, sub);

    if (subString == NULL)
    {
        return -1;
    }
    
    return (subString - str);
}
