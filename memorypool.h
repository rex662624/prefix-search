#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H

typedef struct __MEMORY_POOL {
    char *next;
    char *begin;
    char *end;
} memory_pool;

memory_pool *pool_init(int size);
void *pool_alloc(memory_pool *pool, int size);
void pool_free(memory_pool *pool);

#endif
