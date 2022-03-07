// Coracoralinda version a-01
// Written by Henry Peaurt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static char* errstr;

static int
rand_range(int n)
{
	int x = rand();

	while (x >= RAND_MAX - RAND_MAX % n) {
		x = rand();
	}

	return x;
}

static int
pick_fortune(char fortune[], FILE* file)
{
	char buffer[8192];
	unsigned long count = 0;

	while (fgets(buffer, sizeof buffer, file) != NULL) {
		count++;

		if (count == 0) {
			errstr = "coracoralinda: int overflow: too many fortunes.";
			return -1;
		}

		if (rand_range(count) % count == 0) {
			strncpy(fortune, buffer, 8192);
		}
	}

	if (count > 1) {
		return 0;
	} else {
		errstr = "coracoralinda: empty file: no fortunes to read from.";
		return -1;
	}
}

int
main(void)
{
	char fortune[8192];
	FILE* file = fopen(FORTUNE_PATH, "r");

	if (file == NULL) {
		errstr = "coracoralinda: file error: couldn't open file.";
		goto error;
	}

	srand(time(NULL));

	if (pick_fortune(fortune, file)) {
		goto error;
	} else {
		fputs(fortune, stdout);
		return 0;
	}

error:
	fputs(errstr, stderr);
	return 1;
}
