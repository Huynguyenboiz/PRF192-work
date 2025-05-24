#include <stdio.h>

int main() {
	char c;
	int digits = 0, letters = 0, others = 0;
	printf("Enter the characters (Press Enter to end): ");
	while ((c = getchar()) != '\n') {
		if (c >= '0' && c <= '9') {
			digits++;
		} else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			letters++;
		} else {
			others++;
		}
	}
	printf("Number of digits: %d\n", digits);
	printf("Number of letters: %d\n", letters);
	printf("Number of other keys: %d", others);
	return 0;
}