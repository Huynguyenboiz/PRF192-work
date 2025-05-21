#include <stdio.h>

int main() {
	float income, tax = 0;
	printf("Enter your income per month (million VND): ");
	scanf("%f", &income);
	if (income > 0 && income <= 5) {
		tax = income * 0.05;
	} else if (income > 5 && income <= 10) {
		tax = income * 0.1 - 0.25;
	} else if (income > 10 && income <= 18) {
		tax = income * 0.15 - 0.75;
	} else if (income > 18 && income <= 32) {
		tax = income * 0.2 - 1.65;
	} else if (income > 32 && income <= 52) {
		tax = income * 0.25 - 3.25;
	} else if (income > 52 && income <= 80){
		tax = income * 0.3 - 5.85;
	} else if (income > 80) {
		tax = income * 0.35 - 9.85;
	} else {
		printf("Input error.");
		tax = -1;
	}
	if (tax != -1) {
		tax *= 1000000;
		printf("\nThe personal income tax that you have to pay is %.0f VND.", tax);
	}
	return 0;
}