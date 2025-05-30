#include <stdio.h>
#include <stdlib.h>

int main() {
	int students, passed = 0, failed = 0;
	float score, average, total = 0;
	do {
		printf("Enter the number of students (>= 1): ");
		scanf("%d", &students);
		if (students < 1) {
			printf("Invalid number of students. Please try again.\n");
		}
	} while (students < 1);
	for (int i = 1; i <= students; i++) {
		do {
			printf("Enter the score for student %d (0-10): ", i);
			scanf("%f", &score);
			if (score < 0 || score > 10) {
				printf("Invalid score. Please try again.\n");
			}
		} while (score < 0 || score > 10);
		total += score;
		if (score >= 5) {
			passed += 1;
		} else {
			failed += 1;
		}
	}
	average = total / students;
	printf("\nStatistics: \n");
	printf("Total score of the class: %.0f\n", total);
	printf("Average score of the class: %.2f\n", average);
	printf("Number of students who passed (>= 5): %d\n", passed);
	printf("Number of students who failed (< 5): %d\n", failed);
	system("pause");
	return 0;
}
