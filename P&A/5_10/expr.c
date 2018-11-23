#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* Returns 1 if the argument is valid and 0 otherwise*/
int check_valid_arg (char *arg) {
	char current_ch;

	current_ch = *arg;

	if (current_ch == '\0')
		return 0;

	if (current_ch == '+' || current_ch == '-' || current_ch == '*' || current_ch == '/') {
		/* If the arg is an operator then no addition char is allowed*/
		current_ch = *++arg;
		if (current_ch == '\0'){
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (isdigit(current_ch)) {
			while (current_ch != '\0') {
				if (!isdigit(current_ch))
					return 0;
				current_ch = *arg++;
			}
			return 1;
		}
		else {
			return 0;
		}
	}
}

/* Returns 1 if the argument is a number and 0 otherwise*/
int is_number (char *arg) {
	char current_char;

	current_char = *arg;

	if (isdigit(current_char)) {
		return 1;
	}

	return 0;
}

/* Returns 1 if the arguments are well formed and 0 otherwise*/
int legal_expr (char *arg[200], int size, int op, int numb) {
	int index;
	char *previous, current;

	if(op+1 != numb) {
		return 0;
	}

	if(size < 3) {
		return 0;
	}

	previous = arg[index];

	for (index = 1; index < size; index++) {
		if((!is_number(arg[index-1])) && (is_number(arg[index]))) {
			return 0;
		}
	}
	
	return 1;
}

int main(int argc, char **argv) {
	int count_args = 0;
	int numbers_length = 0;
	int operators_length = 0;
	int i;
	char *numbers[100];
	char *operators[100];
	char *arguments[200];

	if (argv[1] == NULL) {
		printf("No arguments received.\n");
		return 0;
	}

	for (i = 1; i < argc; i++) {
		if (!check_valid_arg(argv[i])) {
			printf("The following argument is invalid: %s\n",argv[i]);
			return 0;
		}
		if(is_number(argv[i])) {
			numbers[numbers_length++] = argv[i];
		}
		else {
			operators[operators_length++] = argv[i];
		}
		arguments[count_args] = argv[i]; 
		count_args++;
	}

	/* Check if the arguments are well formed */
	if (legal_expr) {
		printf("The expression is legal.\n");
	}
	else {
		printf("The expression is not legal.\n");
		return 0;
	}

	
	return 0;
}