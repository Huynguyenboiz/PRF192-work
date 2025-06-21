#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void addValue(int *a, int *n, int value);
int searchValue(int *a, int n, int value);
void printArray(int *a, int n);
void printAscending(int *a, int n);
void printRange(int *a, int n, int min_val, int max_val);

int main() {
    int a[MAX_SIZE];
    int n = 0;
    int choice, value, max_val, min_val;
    do {
        printf("\n---Menu---\n");
        printf("1. Add a value\n");
        printf("2. Search a value\n");
        printf("3. Print out the array\n");
        printf("4. Print out the array in a range\n");
        printf("5. Print out the array in ascending order\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a value to add: ");
                scanf("%d", &value);
                addValue(a, &n, value);
                break;
            case 2:
                printf("Enter a value to search: ");
                scanf("%d", &value);
                {
                  int pos = searchValue(a, n, value);
                  if (pos != -1)
                    printf("Value %d found at position %d.\n", value, pos);
                  else
                    printf("Value %d not found in the array.\n", value);
                }
                break;
            case 3:
                printf("Current array: ");
                printArray(a, n);
                break;
            case 4:
                printf("Enter the range [MIN_VALUE MAX_VALUE]: ");
                scanf("%d %d", &min_val, &max_val);
                printRange(a, n, min_val, max_val);
                break;
            case 5:
                printf("Array in ascending order: ");
                printAscending(a, n);
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

void addValue(int *a, int *n, int value) {
    if (*n >= MAX_SIZE) {
        printf("The array is full, can't add %d into the array.\n", value);
        return;
    }
    a[*n] = value;
    (*n)++;
    printf("Value %d added successfully!\n", value);
}

int searchValue(int *a, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            return i;
        }
    }
    return -1;
}

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void printAscending(int *a, int n) {
    int tempArray[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        tempArray[i] = a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tempArray[i] > tempArray[j]) {
                int temp = tempArray[i];
                tempArray[i] = tempArray[j];
                tempArray[j] = temp;
            }
        }
    }
    printArray(tempArray, n);
}

void printRange(int *a, int n, int min_val, int max_val) {
    for (int i = 0; i <= n; i++) {
    	if (a[i] >= min_val && a[i] <= max_val) {
    		printf("%d ", a[i]);
		}
	}
	printf("\n");
}