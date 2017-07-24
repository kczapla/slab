#include <stddef.h>
#include <stdio.h>

#include "salloc.h"
#include "slab.h"

int main(int argc, char const* argv[])
{
    int *x = (int *) alloc_objects(sizeof(int), 400);
    x[50] = 19999;
    x[0] = 1;
    printf("%p\n", x);
    printf("%i, %i, %i\n", x[0], x[50], x[30]);
    char *y = (char *) alloc_objects(sizeof(char), 400);
    y = "adam";
    printf("%s\n", y);
    return 0;
}
