// You know you should actually use a buffer to read the phrases and output everything if the buffer is full and keep reading and outputing until newline

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

FILE *tocount;
FILE *toread;

int count_lines(void);
void go_to_phrase(int lines);
char *get_phrase(void);

int main(void)
{
	tocount = fopen("/usr/share/coracoralinda/phrases.txt", "r") ;
	toread = fopen("/usr/share/coracoralinda/phrases.txt", "r");

	int lines = count_lines();
	srand(time(0));
	go_to_phrase(rand() % lines - 1);
	char *phrase = get_phrase();
	printf("%s\n", phrase);

	return 0;
}


int count_lines(void)
{
	int lines = 0;
	char c;

	while ((c = fgetc(tocount)) != EOF) {
		if (c == '\n')
			++lines;
	}
	return lines;
}


void go_to_phrase(int lines)
{
	char c;

	for (int i = 0; i < lines;) {
		c = fgetc(toread);
		if (c == '\n')
			++i;
	}
}


char *get_phrase(void)
{
	char c;
	char *phrase = malloc(100);
	int capacity = 100;
	int used = 0;

	while ((c = fgetc(toread)) != '\n') {
		phrase[used++] = c;
		if (used == capacity - 1)
			phrase = realloc(phrase, capacity += 100);
	}
	phrase[used] = '\0';
	return phrase;
}
