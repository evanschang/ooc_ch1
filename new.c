#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "new.h"

void* new(const void *type, ...)
{
	const size_t size = *(const size_t *)type;
	void *p = calloc(1, size);

	assert(p); //should use general technique for handling exception in CH.13
	return p;
}

void delete(void *_item)
{
	free(_item);
}
