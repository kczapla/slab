#include <stdlib.h>
#include "slab.h"


void *alloc_objects(size_t objs, object_count oc) {
    void* objp = malloc(objs * oc);
    return objp;
}
