#include <stdio.h>

int main() {
	float kms, fare;
	printf("Enter the number of kilometers traveled to calculate the taxi fare: ");
	scanf("%f", &kms);
	if (kms > 0 && kms < 2) {
		fare = kms * 10000;
	} else if (kms >= 2 && kms <= 31) {
		fare = 10000 + (kms - 2) * 8000;
	} else if (kms > 31) {
		fare = 242000 + (kms - 31) * 6000;
	} else {
		printf("Invalid input.");
		fare = -1;
	}
	if (fare != -1) {
		printf("The taxi fare you need to pay is %.3f", fare);
	}
	return 0;
}
