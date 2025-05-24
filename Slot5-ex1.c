#include <stdio.h>

int main() {
	int num, sum = 0;
	printf("Enter the integers to calculate sum (Enter 0 to end): ");
	while (1) {
		scanf("%d", &num);
		if (num == 0) {
			break;
		}
		sum += num;
	}
	printf("Sum of them is %d", sum);
	return 0;
}