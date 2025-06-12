#include <stdio.h>

float sumExpression(int n) {
	float sum = 0.0;
	for (int i = 1; i <= 2 * n + 1; i += 2) {
		sum += 1.0 / i;
	}
	return sum;
}
int main() {
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	float sum = sumExpression(n);
	printf("\nThe result is: %.6f", sum);
	return 0;
}