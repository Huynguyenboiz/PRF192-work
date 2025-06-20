#include <stdio.h>
#define MAX_SIZE 100

void inputArray(int arr[], int *size);
void displayArray(int arr[], int size);
int searchValue(int arr[], int size, int target);
void calculateStatistics(int arr[], int size);
void reverseArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE], size = 0, target, index, choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Input data\n");
        printf("2. Display array\n");
        printf("3. Search for a number\n");
        printf("4. Calculate statistics (Sum, Average, Max, Min)\n");
        printf("5. Reverse array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputArray(arr, &size);
                break;
            case 2:
                if (size > 0) {
                	printf("Array elements:\n");
                    displayArray(arr, size);
                } else {
                    printf("No data to display. Please input data first.\n");
                }
                break;
            case 3:
                if (size > 0) {
                    printf("Enter the number you want to search for: ");
                    scanf("%d", &target);
                    index = searchValue(arr, size, target);
                    if (index == -1) {
                        printf("The number %d is not found in the array.\n", target);
                    } else {
                        printf("The number %d is found at index %d.\n", target, index);
                    }
                } else {
                    printf("No data available to search. Please input data first.\n");
                }
                break;
            case 4:
                if (size > 0) {
                    calculateStatistics(arr, size);
                } else {
                    printf("No data available to calculate statistics. Please input data first.\n");
                }
                break;
            case 5:
                if (size > 0) {
                	printf("Reverse Array: ");
                    reverseArray(arr, size);
                    displayArray(arr, size);
                } else {
                    printf("No data to reverse. Please input data first.\n");
                }
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}

void inputArray(int arr[], int *size) {
    do {
    	printf("Enter the size of the array (max 100): ");
    	scanf("%d", size);
    	if (*size < 1 || *size > MAX_SIZE) {
   			printf("Invalid size. Please enter again.\n");
		}
	} while (*size < 1 || *size > MAX_SIZE);
	printf("Enter %d elements: \n", *size);
   	for (int i = 0; i < *size; i++) {
    	printf("Number %d: ", i);
       	scanf("%d", &arr[i]);
	}
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int searchValue(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
    	if (arr[i] == target) {
    		return i;
		}
	}
    return -1;
}

void calculateStatistics(int arr[], int size) {
    int sum = 0, max = arr[0], min = arr[0];
    double average = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    average = (double)sum / size;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}

void reverseArray(int arr[], int size) {
    int temp;
    for(int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
