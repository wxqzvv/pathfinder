#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if (!str || !sub || !replace)
    {
        return NULL;
    }

    int sbs_count = mx_count_substr(str, sub);
    int sb_len = mx_strlen(sub);
    int rp_len = mx_strlen(replace);

    char *rslt = mx_strnew(mx_strlen(str) + (rp_len - sb_len) * sbs_count);
    char *tmp = rslt;

    while (sbs_count--)
    {
        int len_front = mx_get_substr_index(str, sub);
        tmp = mx_strncpy(tmp, str, len_front) + len_front;
        tmp = mx_strcpy(tmp, replace) + rp_len;
        str += len_front + sb_len;
    }
    mx_strcpy(tmp, str);
    
    return rslt;
}
