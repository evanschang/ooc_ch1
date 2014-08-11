#include <stddef.h>
#include "Object.h"

static const size_t _Object = sizeof(struct Object);
const void *Object = &_Object;

int differ(const void *a, const void *b)
{
	return 0;
}
