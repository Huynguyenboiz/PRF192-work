#include <stdio.h>

int main() {
	const int LV1 = 1984, LV2 = 2050, LV3 = 2380, LV4 = 2998, LV5 = 3350, LV6 = 3460;
	float kwh, price = 0;
	printf("Enter the amount of electricity you have used in last month (kwh): ");
	scanf("%f", &kwh);
	if (kwh > 0 && kwh <= 50) {
		price = kwh * LV1;
	} else if (kwh >= 51 && kwh <= 100) {
		price = LV1 * 50 + (kwh - 50) * LV2;
	} else if (kwh >= 101 && kwh <= 200) {
		price = LV1 * 50 + LV2 * 50 + (kwh - 100) * LV3;
	} else if (kwh >= 201 && kwh <= 300) {
		price = LV1 * 50 + LV2 * 50 + LV3 * 100 + (kwh - 200) * LV4;
	} else if (kwh >= 301 && kwh <= 400) {
		price = LV1 * 50 + LV2 * 50 + LV3 * 100 + LV4 * 100 + (kwh - 300) * LV5;
	} else if (kwh > 400){
		price = LV1 * 50 + LV2 * 50 + LV3 * 100 + LV4 * 100 + LV5 * 100 + (kwh - 400) * LV6;
	} else {
		printf("Input error.");
		price = -1;
	}
	if (price != -1) {
		price += price * 8 / 100;
		printf("\nThe total cost of electricity that you have to pay is %.3f VND.", price);
	}
	return 0;
}