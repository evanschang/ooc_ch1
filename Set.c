#include <stddef.h>
#include <assert.h>
#include "Set.h"
#include "Object.h"

struct Set {
	unsigned count;
};

static const size_t _Set = sizeof(struct Set);

const void *Set = &_Set;

void* add(void *_set, const void *_element)
{
	struct Set *set = _set;
	struct Object *element = (void*)_element;

	assert(set);
	assert(element);

	if(!element->in)
		element->in = set;
	else
		assert(element->in == set);
	++element->count, ++set->count;
	return element;
}

void* find(const void *_set, const void *_element)
{
	struct Object *element = (void*)_element;

	assert(_set);
	assert(element);

	return element->in == _set ? (void*) element : 0;
}

void* drop(void *_set, const void *_element)
{
	struct Set *set = _set;
	struct Object *element = (void*)_element;

	if(element)
	{
		if(--element->count == 0)
			element->in = 0;
		--set->count;
	}
	return element;
}

int contains(const void *_set, const void *_element)
{
	return find(_set, _element) != 0;
}

unsigned count (const void *_set)
{
	const struct Set *set = _set;

	assert(set);
	return set->count;
}
