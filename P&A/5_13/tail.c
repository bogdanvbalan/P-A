
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	int n = 10;
	int i;
	char line[512];

	if (argv[1] != NULL) {
		n = atoi(argv[1]);
		n *= -1;
	}

	char *last_n_lines[n];
	int current_pos = 0;

	do {
		printf("Enter a line or q to quit.\n");
		scanf("%s", line);
		getc(stdin);
		if(strcmp(line,"q") != 0) {
			last_n_lines[current_pos] = malloc(sizeof(*line));
			strcpy(last_n_lines[current_pos], line);
			if (current_pos == n-1) {
				current_pos = 0;
			}
			else {
				current_pos++;
			}
		}
	} while (strcmp(line,"q") != 0);

	printf("Printing the last %d lines.\n", n);
	for (i = n-1; i >= 0; i--) {
		printf("%s\n", last_n_lines[i]);
	}

	return 0;
}