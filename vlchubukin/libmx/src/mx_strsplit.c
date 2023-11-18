#include "../inc/libmx.h"

static int count_char(const char *s, char c)
{
    int i = 0;

    while (s[i] != c && s[i])
    {
        i++;
    }

    return i;
}

char **mx_strsplit(const char *s, char c)
{
    if (!s)
    {
        return NULL;
    }

    char **charArr = (char **)malloc(sizeof(char *) * (mx_count_words(s, c) + 1));
    int word_lenth = 0;
    int i = 0;

    while ((*s) && (*s != '\0'))
    {
        if (*s != c)
        {
            word_lenth = count_char(s, c);
            charArr[i++] = mx_strndup(s, word_lenth);
            s += word_lenth;
            continue;
        }
        s++;
    }
    charArr[i] = NULL;
    
    return charArr;
}
