// Coracoralinda v0.3.0-alpha
// Written by Henry Peaurt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getopt.h>

#define BUF 8192

typedef enum {
	NONE,
	INTEGER_OVERFLOW,
	EMPTY_FILE,
	NO_FILE,
	FLAG_ERR
} err_t;

typedef struct {
	char fortune[BUF];
	FILE* file;
} ctx;

static err_t pick_fortune(ctx* c);
static int rand_range(int n);
static err_t add_fortune(void);

int
main(int argc, char* argv[])
{
	int flag;
	err_t err = NONE;
	ctx c = {
		.file = fopen(FORTUNE_PATH, "r")
	};

	if (c.file == NULL) {
		err = NO_FILE;
		goto end;
	}

	srand(time(NULL));

	if (argc == 1) {
		err = pick_fortune(&c);
	} else {
		while ((flag = getopt(argc, argv, "a:p")) != -1 && err == NONE) {
			switch (flag) {
			case 'a':
				err = add_fortune();
				break;
			case 'p':
				err = pick_fortune(&c);
				break;
			case ':':
			case '?':
				err = FLAG_ERR;
				goto end;
			}
		}
	}

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
	case FLAG_ERR:
		return 1;

	}
}

static err_t
pick_fortune(ctx* c)
{
	char buffer[BUF];
	unsigned long count = 0;

	while (fgets(buffer, sizeof buffer, c->file) != NULL) {
		count++;

		if (count == 0) {
			return INTEGER_OVERFLOW;
		}

		if (rand_range(count) % count == 0) {
			strncpy(c->fortune, buffer, BUF);
		}
	}

	if (count == 0) {
		return EMPTY_FILE;
	}

	return NONE;
}

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
add_fortune(void)
{
	FILE* file = fopen(FORTUNE_PATH, "a");

	if (file == NULL) {
		return NO_FILE;
	}

	fprintf(file, "%s\n", optarg);

	fclose(file);

	return NONE;
}
