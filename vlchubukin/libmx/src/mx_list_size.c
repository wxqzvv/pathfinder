#include "../inc/libmx.h"

int mx_list_size(t_list *list)
{
    t_list *nd = list;
    int sz = 0;

    while (nd != NULL)
    {
        nd = nd->next;
        sz++;
    }

    return sz;
}
