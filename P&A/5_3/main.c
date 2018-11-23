#include <stdio.h>

void my_strcat(char *dest, char *source) {

	while (*dest) {
		dest++;
	} //place at the end of the dest

	while(*source) {
		*dest = *source;
		source++;
		dest++;
	}

	*dest = '\0';
}

int main () {
	char a[100];
	char b[50] = {"Hello"};

	my_strcat(a,b);
	printf("%s.\n", a);
	return 0;
}