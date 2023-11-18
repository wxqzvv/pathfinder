#include "../inc/libmx.h"

char *mx_strtrim(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }
    
    int srt = 0;
    while (mx_isspace(str[srt]))
    {
        srt++;
    }

    int end = mx_strlen(str) - 1;
    while (mx_isspace(str[end]))
    {
        end--;
    }

    if (srt > mx_strlen(str) || end < 0)
    {
        return mx_strdup("");
    }

    char *rslt = mx_strnew( end - srt + 1);
    mx_strncpy(rslt, &str[srt], end - srt + 1);

    return rslt;
}
