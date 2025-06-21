#include <stdio.h>
#define MAX_ROW 100
#define MAX_COL 100

void get2D_Array(int a[][MAX_COL], int *row, int *col);
void print2D_Array(int a[][MAX_COL], int row, int col);
int findMax(int a[][MAX_COL], int row, int col);
void sumOfRows(int a[][MAX_COL], int row, int col);

int main() {
    int a[MAX_ROW][MAX_COL];
    int row = 0, col = 0, choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Add a 2D-Array\n");
        printf("2. Display the 2D-Array\n");
        printf("3. Find max of the 2D-Array\n");
        printf("4. Calculate sum of rows in 2D-Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                get2D_Array(a, &row, &col);
                break;
            case 2:
                print2D_Array(a, row, col);
                break;
            case 3:
                printf("Max value of the 2D-Array: %d\n", findMax(a, row, col));
                break;
            case 4:
                sumOfRows(a, row, col);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void get2D_Array(int a[][MAX_COL], int *row, int *col) {
    printf("Enter number of rows: ");
    scanf("%d", row);
    printf("Enter number of columns: ");
    scanf("%d", col);
    printf("Enter elements of the array:\n");
    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            printf("Arr[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void print2D_Array(int a[][MAX_COL], int row, int col) {
    printf("\nArray 2D:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int findMax(int a[][MAX_COL], int row, int col) {
    int max = a[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (a[i][j] > max) max = a[i][j];
        }
    }
    return max;
}

void sumOfRows(int a[][MAX_COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += a[i][j];
        }
        printf("Sum of row %d = %d\n", i, sum);
    }
}