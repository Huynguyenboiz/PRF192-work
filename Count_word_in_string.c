#include <stdio.h>
#include <string.h>
#include <ctype.h>

int wordcount(char str[]) {
	int count = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) {
			count++;
		}
	}
	return count;
}

int main() {
	char s[100];
	printf("Enter a string: ");
	scanf("%[^\n]", s);
	int words = wordcount(s);
	printf("There are %d words in the string entered.", words);
	return 0;
}