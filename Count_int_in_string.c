#include <stdio.h>
#include <string.h>
#include <ctype.h>

int intcount(char str[]) {
	int count = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (isdigit(str[i]) == 1 && (i == 0 || isdigit(str[i - 1]) == 0)) {
			count += 1;
		}
	}
	return count;
}
int main() {
	char s[100];
	printf("Enter a string: ");
	scanf("%s", s);
	int integers = intcount(s);
	printf("There are %d integers in the string entered.", integers);
	return 0;
}