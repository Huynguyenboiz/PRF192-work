#include <stdio.h>

int main() {
	float num1, num2, result;
	char op;
	printf("Enter an operation to calculate [+, -, x, /]: ");
	scanf("%f%c%f", &num1, &op, &num2);
	switch (op) {
		case '+': result = num1 + num2; break;
		case '-': result = num1 - num2; break;
		case 'x': result = num1 * num2; break;
		case '/': result = num1 / num2; break;
	}
	printf("The result is %.2f", result);
	return 0;
}