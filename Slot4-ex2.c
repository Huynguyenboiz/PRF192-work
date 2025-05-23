#include <stdio.h>
int main() {
	int month, day;
	printf("Enter day, month to check: ");
	scanf("%d %d", &day, &month);
	if (day < 1 || day > 31) {
		printf("Invalid day\n");
	}
	if (month < 1 || month > 12) {
		printf("Invalid month");
	} else {
		printf("Day and month are valid.");
	}
	return 0;
}