#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n)
{
    if (s1 == s2 || n == 0)
    {
        return 0;
    }

    unsigned char *d = (unsigned char *)s1;
    unsigned char *y = (unsigned char *)s2;

    for (size_t i = 0; i < n; i++)
    {
        if (d[i] != y[i])
        {
            return d[i] - y[i];
        }
    }

    return 0;
}
