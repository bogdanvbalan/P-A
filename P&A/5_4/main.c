
#include <stdio.h>

int strend(char *str1, char *str2) {
	int chars_str2 = 0;
	char *temp_str1 = str1;
	char *temp_str2 = str2;

	/* Get the length of str2*/
	while (*temp_str2) {
		chars_str2++;
		temp_str2++;
	} 

	/* Get to the end of str1 */
	while (*temp_str1) {
		temp_str1++;
	}

	/* Get in position for both strings*/
	temp_str1 -= chars_str2;
	temp_str2 -= chars_str2;

	/* Check if they match*/
	while (chars_str2--) {
		if ((*temp_str1) != (*temp_str2))
			return 0;
	}

	return 1;
}

int main() {
	char a[100] = {"HelloWorld"};
	char b[100] = {"Worlds"};


	printf("%d\n", strend(a,b));
	return 0;
}