#include "../inc/libmx.h"

int mx_count_words(const char *str, char c)
{
    if (str == NULL)
    {
        return -1;
    }

    if (mx_strcmp(str, "") == 0)
        return 0;

    int wrds = 0, ctr = 0;
    str++;
    
    while (*str != '\0')
    {
        if (*str == c)
        {
            if (*(str - 1) != c)
            {
                wrds++;
            }
        }
        str++;
        ctr++;
    }
    if (*(str - 1) != c && ctr)
    {
        wrds++;
    }
    return wrds;
}
