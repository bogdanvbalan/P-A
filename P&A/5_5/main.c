#include <stdio.h>

void my_strncpy(char *dest, char *source, int n) {
	if (n == 0) 
		return;

	while (*dest) {
		*dest = *source;
		dest++;
		source++;
		n--;
		if (n == 0)
			return;
	}
}

void my_strncat(char *dest, char *source, int n) {

	while(*dest) {
		dest++;
	}

	while(n) {
		*dest = *source;
		dest++;
		source++;
		n--;
	}
	return;
}

int main() {
	char a[100];
	char b[100] = {"RandomWord"};
	int n = 5;

	my_strncpy(a,b,n);
	printf("%s\n",a);
	my_strncat(a,b,n);
	printf("%s\n",a);
}