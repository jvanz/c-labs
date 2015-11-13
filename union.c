
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

union {
	char c;
	long l;
	int i;
	void *p;
} simple;

union {
	char c;
	int i;
} simple2;

union {
	char c;
	struct {
		long l;
		char b;
	} s;
} unistruc;

typedef long Align;
union header {
	struct {
		union header *ptr;
		unsigned size;
	} s;
	Align x;
};

typedef union header Header;

struct s {
	union header *ptr;
	unsigned size;
};

typedef struct s S;


int main(int argc, char **argv)
{
	simple.c = 'a';
	printf("sizeof(simple): %zu\n", sizeof(simple));
	assert(sizeof(void*) == sizeof(simple));
	simple2.c = 'a';
	printf("sizeof(simple2): %zu\n", sizeof(simple2));
	assert(sizeof(int) == sizeof(simple2));
	unistruc.c = 'a';
	printf("sizeof(unistruc): %zu\n", sizeof(unistruc));
	assert((sizeof(long) + sizeof(long)) == sizeof(unistruc));
	printf("sizeof(Header): %zu\n", sizeof(Header));
	printf("sizeof(S): %zu\n", sizeof(S));
	union header *ptr;
	printf("sizeof(ptr): %zu\n", sizeof(ptr));

}
