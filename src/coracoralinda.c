#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getopt.h>

#define BUF 8192

typedef enum {
	OK,
	INTEGER_OVERFLOW,
	EMPTY_FILE,
	NO_FILE,
	FLAG_ERR
} err_t;

char fortune[BUF];
FILE* src;

static err_t pick_fortune(void);
static int rand_range(int n);

int
main(int argc, char* argv[])
{
	src = fopen(FORTUNE_PATH, "r");
	err_t err = OK;

	if (src == NULL) {
		err = NO_FILE;
		goto end;
	}

	srand(time(NULL));

	if (argc == 1) {
		err = pick_fortune();
	} else {
		char flag;

		while ((flag = getopt(argc, argv, "p")) != -1 && err == OK) {
			switch (flag) {
			case 'p':
				err = pick_fortune();
				break;
			case ':':
			case '?':
				err = FLAG_ERR;
				goto end;
			}
		}
	}

end:
	fclose(src);

	switch (err) {
	case OK:
		fputs(fortune, stdout);
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
pick_fortune(void)
{
	char buffer[BUF];
	unsigned long count = 0;

	while (fgets(buffer, sizeof buffer, src) != NULL) {
		count++;

		if (count == 0)
			return INTEGER_OVERFLOW;

		if (rand_range(count) % count == 0)
			strncpy(fortune, buffer, BUF);
	}

	if (count == 0)
		return EMPTY_FILE;

	return OK;
}

static int
rand_range(int n)
{
	int x = rand();

	while (x >= RAND_MAX - RAND_MAX % n)
		x = rand();

	return x;
}
