#include <stdio.h>

int main() {
	int num;
	printf("Enter a number to get currency units name [1: USD, 2: EUR, 3: VND, 4: JPY]: ");
	scanf("%d", &num);
	switch (num) {
		case 1: printf("United States Dollars"); break;
		case 2: printf("Euro"); break;
		case 3: printf("Vietnamese Dong"); break;
		case 4: printf("Japanese Yen"); break;
		default: printf("Invalid input.");
	}
	return 0;
}