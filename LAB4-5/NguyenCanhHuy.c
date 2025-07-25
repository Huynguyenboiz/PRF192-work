#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int readFileToArray(const char *filename, int arr[], int *size);
void displayArray(int arr[], int size);
void calculateStatistics(int arr[], int size, int *sum, float *average, int *max, int *min);
void writeResultsToFile(const char *filename, int sum, float average, int max, int min);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int sum, max, min;
    float average;
    const char *inputFile = "data.txt";
    const char *outputFile = "results.txt";
    int choice;
    int dataLoaded = 0;
    int statsCalculated = 0;
    do {
		printf("\n----------- PROGRAM MENU -----------\n");
    	printf("1. Read data from file\n");
    	printf("2. Display data in the array\n");
    	printf("3. Calculate and display statistics\n");
    	printf("4. Write results to file\n");
    	printf("5. Exit program\n");
    	printf("------------------------------------\n");
        printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1:
                if (readFileToArray(inputFile, arr, &size)) {
                    printf("Successfully read data from file '%s'.\n", inputFile);
                    printf("Found %d numbers in the file.\n", size);
                    dataLoaded = 1;
                    statsCalculated = 0;
                } else {
                    dataLoaded = 0;
                }
                break;
            case 2:
                if (dataLoaded) {
                    displayArray(arr, size);
                } else {
                    printf("Please read data from the file first (select option 1).\n");
                }
                break;
            case 3:
                if (dataLoaded) {
                    calculateStatistics(arr, size, &sum, &average, &max, &min);
                    statsCalculated = 1;
                    printf("\nStatistics:\n");
                    printf("Sum: %d\n", sum);
                    printf("Average: %.2f\n", average);
                    printf("Maximum: %d\n", max);
                    printf("Minimum: %d\n", min);
                } else {
                    printf("Please read data from the file first (select option 1).\n");
                }
                break;
            case 4:
                if (statsCalculated) {
                    writeResultsToFile(outputFile, sum, average, max, min);
                    printf("Results have been written to file '%s'.\n", outputFile);
                } else {
                    printf("Please calculate statistics first (select option 3).\n");
                }
                break;
            case 5:
                printf("Exiting...\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    system("pause");
    return 0;
}

int readFileToArray(const char *filename, int arr[], int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open the file '%s' to read.\n", filename);
        return 0;
    }
    *size = 0;
    while (*size < MAX_SIZE && fscanf(file, "%d", &arr[*size]) == 1) {
        (*size)++;
    }
    fclose(file);
    return 1;
}

void displayArray(int arr[], int size) {
    printf("Data in the array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void calculateStatistics(int arr[], int size, int *sum, float *average, int *max, int *min) {
    *sum = 0;
    if (size > 0) {
        *max = arr[0];
        *min = arr[0];
    }
    for (int i = 0; i < size; i++) {
        *sum += arr[i];

        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
    if (size > 0) {
        *average = (float)(*sum) / size;
    } else {
        *average = 0;
    }
}

void writeResultsToFile(const char *filename, int sum, float average, int max, int min) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Cannot open the file '%s' to write.\n", filename);
        return;
    }
    fprintf(file, "Sum: %d\n", sum);
    fprintf(file, "Average: %.2f\n", average);
    fprintf(file, "Maximum: %d\n", max);
    fprintf(file, "Minimum: %d\n", min);
    fclose(file);
}
