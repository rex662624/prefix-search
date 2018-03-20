#include <stdlib.h>
#include <string.h>

#include "memorypool.h"

//static memory_pool *pool = NULL;

//---------memory pool----------------------
memory_pool *pool_init(int size)
{
    memory_pool *pool = (memory_pool *) malloc(sizeof(memory_pool));

    pool->begin = pool->next = (char *) calloc(1, size);
    pool->end = pool->begin + size;

    return pool;
}

void *pool_alloc(memory_pool *pool, int size)
{
    if (pool->end - pool->next < size)
        return NULL;

    void *result = pool->next;
    pool->next += size;

    return result;
}

void pool_free(memory_pool *pool)
{

    free(pool->begin);
    free(pool);

}


