#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n)
{
    if (s == NULL)
    {
        return NULL;
    }

    unsigned char *string_1 = (unsigned char *)s;

    string_1 += mx_strlen(s);

    while (n--)
    {
        if (*string_1 == (unsigned char)c)
        {
            return string_1;
        }
        string_1--;
    }

    return NULL;
}
