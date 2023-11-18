#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data)
{
    t_list *newNode = mx_create_node(data);
    t_list *lastNode = *list;

    if (*list == NULL)
    {
        *list = newNode;
        return;
    }

    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
}
