#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *))
{
    if (lst == NULL)
    {
        return NULL;
    }

    t_list *node1 = lst;
    t_list *node2 = NULL;
    int no_swap = 0;
    void *temp;

    while(!no_swap)
    {
        no_swap = 1;
        node1 = lst;

        while (node1->next != node2)
        {
            if (cmp(node1->data, node1->next->data))
            {
                temp = node1->data;
                node1->data = node1->next->data;
                node1->next->data = temp;
                no_swap = 0;
            }
            node1 = node1->next;
        }
        node2 = node1;
    }

    return lst;
}
