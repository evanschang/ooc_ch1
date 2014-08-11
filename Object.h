#ifndef OBJECT_H_
#define OBJECT_H_

struct Object {
	unsigned count;
	struct Set *in;
};

extern const void *Object;

int differ(const void *a, const void *b);

#endif /* OBJECT_H_ */
