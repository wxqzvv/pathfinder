#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
    {
        return malloc(size);
    }
    if (size == 0)
    {
        free(ptr);
        return NULL;
    }

    size_t old_size = sizeof(ptr);

    if (size <= old_size)
    {
        return ptr;
    }

    void *new_ptr = malloc(size);

    if (new_ptr == NULL)
    {
        return NULL; // Allocation failed
    }

    mx_memcpy(new_ptr, ptr, old_size);

    free(ptr);

    return new_ptr;
}
