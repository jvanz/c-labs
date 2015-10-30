
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct {
	long l;
	char b;
} ss;
struct {
	char b;
	short b2;
} cc;

struct {
	int i;
	short i2;
} ii;

struct __attribute__((packed)) {
	int i;
	short i2;
} ii_packed;

int main(int argc, char **argv)
{
	printf("sizeof(int): %zu\n", sizeof(int));
	printf("sizeof(short): %zu\n", sizeof(short));
	printf("sizeof(char): %zu\n", sizeof(char));
	printf("sizeof(long): %zu\n", sizeof(long));
	printf("sizeof(ss): %zu\n", sizeof(ss));
	printf("sizeof(cc): %zu\n", sizeof(cc));
	printf("sizeof(ii): %zu\n", sizeof(ii));
	printf("sizeof(ii) packed: %zu\n", sizeof(ii_packed));
	assert(16 == sizeof(ss));
	assert(4 == sizeof(cc));
	assert(8 == sizeof(ii));
	assert(6 == sizeof(ii_packed));
}
