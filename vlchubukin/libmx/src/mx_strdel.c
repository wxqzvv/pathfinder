#include "../inc/libmx.h"

void mx_strdel(char **str)
{
    if (str == NULL)
    {
        return;
    }
    
    free(*str);
    *str = NULL;
}
