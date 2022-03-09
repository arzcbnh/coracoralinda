// Coracoralinda v0.2.1-alpha
// Written by Henry Peaurt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF 8192

typedef enum {
	NONE,
	INTEGER_OVERFLOW,
	EMPTY_FILE,
	NO_FILE
} err_t;

typedef struct {
	char fortune[BUF];
	FILE* file;
} cntxt;

static int
rand_range(int n)
{
	int x = rand();

	while (x >= RAND_MAX - RAND_MAX % n) {
		x = rand();
	}

	return x;
}

static err_t
pick_fortune(char fortune[], FILE* file)
{
	char buffer[BUF];
	unsigned long count = 0;

	while (fgets(buffer, sizeof buffer, file) != NULL) {
		count++;

		if (count == 0) {
			return INTEGER_OVERFLOW;
		}

		if (rand_range(count) % count == 0) {
			strncpy(fortune, buffer, BUF);
		}
	}

	if (count > 1) {
		return NONE;
	}

	return EMPTY_FILE;
}

static err_t
run(cntxt* c)
{
	if (c->file == NULL) {
		return NO_FILE;
	}

	srand(time(NULL));
	return pick_fortune(c->fortune, c->file);
}

int
main(void)
{
	cntxt c;
	c.file = fopen(FORTUNE_PATH, "r");

	err_t err = run(&c);
	goto end;

end:
	fclose(c.file);

	switch (err) {
	case NONE:
		fputs(c.fortune, stdout);
		return 0;
	case INTEGER_OVERFLOW:
		fputs("coracoralinda: integer overflow: too many fortunes\n", stderr);
		return 1;
	case EMPTY_FILE:
		fputs("coracoralinda: empty file: no fortunes to be read\n", stderr);
		return 1;
	case NO_FILE:
		fputs("coracoralinda: couldn't open fortune file\n", stderr);
		return 1;
	}
}
