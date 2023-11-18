#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n)
{
    if (s == NULL)
    {
        return NULL;
    }
    
    unsigned char *string_0 = (unsigned char *)s;

    while (n--)
    {
        if (*string_0 == (unsigned char)c)
        {
            return string_0;
        }
        string_0++;
    }
    
    return NULL;
}
