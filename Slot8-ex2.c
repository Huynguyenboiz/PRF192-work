#include <stdio.h>

int main() {
	float num1, num2, num3;
	printf("Enter 3 real number: ");
	scanf("%f %f %f", &num1, &num2, &num3);
	float min = num1;
	if (num2 < min) min = num2;
	if (num3 < min) min = num3;
	printf("Smallest number in the 3 numbers you just entered is: %f", min);
	return 0;
}
