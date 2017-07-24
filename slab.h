#ifndef SLAB_H
#define SLAB_H

#include <stddef.h>

typedef unsigned int object_count;

//size_t caches_size = {4096};

struct slab {
    size_t object_size;
    int object_count;
    int free;  // next free object in the slab. LIFO queue.
    void* memp;
};

struct cache {
    size_t objects_size;
    int slab_count;
    struct slab* slabp;
};

static struct cache_cache {
    struct cache* cachep;
    int cache_count;
} cache_list;


void init_cache();
struct cache* alloc_cache(size_t obj_size, int slab_count);
int free_cache(struct cache* cachep);

struct slab* alloc_slab(size_t objs, object_count oc);
int free_slab(struct slab* slabp);

void *alloc_objs(size_t objs, object_count oc);
int dealloc_obj(void* objp, object_count oc);

#endif
