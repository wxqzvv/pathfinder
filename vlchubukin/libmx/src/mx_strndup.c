#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    size_t len = n > (size_t)mx_strlen(s1) ? (size_t)mx_strlen(s1) : n;

    char *duplicate = mx_strnew(len);

    if (duplicate == NULL)
    {
        return NULL;
    }

    duplicate = mx_strncpy(duplicate, s1, len);

    return duplicate;
}
