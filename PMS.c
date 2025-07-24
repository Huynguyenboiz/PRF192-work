#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "products.bin"

typedef struct {
	int product_id;
	char product_name[50];
	float price;
	int quantity;
} Product;

void writeProducts();
void appendProducts();
void readProducts();
void modifyProducts();
void removeProducts();
int checkExist(int id);

int main() {
	int choice;
	do {
		printf("\n--- Product Managerment System ---\n\n");
		printf("1. Write Products\n");
		printf("2. Append Products\n");
		printf("3. Read Products\n");
		printf("4. Modify Products\n");
		printf("5. Remove Products\n");
		printf("6. Exit\n\n");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) {
			printf("Invalid input. Please enter a number.\n");
			fflush(stdin);
			continue;
		}
		switch(choice) {
			case 1: writeProducts(); 	break;
			case 2: appendProducts();	break;
			case 3: readProducts();		break;
			case 4: modifyProducts();	break;
			case 5: removeProducts(); 	break;
			case 6: printf("Exiting...\n--- The program has ended ---\n"); break;
			default: printf("Invalid choice. Please try again\n");
		}
	} while (choice != 6);
	return 0;
}

void writeProducts() {
	int n;
	printf("Enter the number of products to write: ");
	scanf("%d", &n);
	
	Product *products = (Product*) malloc(n * sizeof(Product));
	int valid;
	for (int i = 0; i < n; i++) {
		printf("\nEnter details for product %d:\n", i + 1);
		do {
			valid = 1;
			printf("Product ID: ");
			scanf("%d", &products[i].product_id);
			for (int j = 0; j < i; j++) {
				if (products[i].product_id == products[j].product_id) {
					printf("Product ID must be unique. Please try again.\n");
					valid = 0;
					break;
				}
			}
		} while (valid != 1);
		fflush(stdin);
		printf("Product Name: ");
		scanf("%[^\n]", &products[i].product_name);
		printf("Price: ");
		while (scanf("%f", &products[i].price) != 1 || products[i].price < 0) {
			printf("Invalid price. Enter it again: ");
			fflush(stdin);
		}
		while (scanf("%d", &products[i].quantity) != 1 || products[i].quantity < 0) {
			printf("Invalid quantity. Enter it again: ");
			fflush(stdin);
		}
		fflush(stdin);
	}
	
	FILE *fp = fopen(FILENAME, "wb");
	if (fp == NULL) {
		printf("File error. Cannot write to file.\n");
		free(products);
		return;
	}
	fwrite(products, sizeof(Product), n, fp);
	fclose(fp);
	free(products);
	printf("\nProducts have been written to the file successfully.\n");
}

void appendProducts() {
	int n;
	printf("Enter the number of products to append: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Invalid number!\n");
		fflush(stdin);
		return;
	}
	Product prod;
	int valid;
	FILE *fp = fopen(FILENAME, "ab+");
	if (fp == NULL) {
		printf("File error: Unable to append to the file.\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		printf("\nEnter details for product %d:\n", i + 1);
		do {
			valid = 1;
			printf("Product ID: ");
			if (scanf("%d", &prod.product_id) != 1) {
                          valid = 0;
                          printf("Invalid input. Please enter an integer.\n");
                          while (getchar() != '\n');
                          continue;
                        };
			if (checkExist(prod.product_id) != 1) {
				printf("Product ID is already exists! Enter another ID.\n");
				valid = 0;
			}
		} while (valid != 1);
		fflush(stdin);
		printf("Product Name: ");
		scanf("%[^\n]", prod.product_name);
		fflush(stdin);
		printf("Price: ");
		while (scanf("%f", &prod.price) != 1 || prod.price < 0) {
			printf("Invalid price. Please enter again.\n");
			while (getchar() != '\n');
		}
		fflush(stdin);
		fwrite(&prod, sizeof(Product), 1, fp);
	}
	fclose(fp);
	printf("\nProducts have been appended to the file successfully.\n");
}

void readProducts() {
	FILE *fp = fopen(FILENAME, "rb");
	if (fp == NULL) {
		printf("File not found!\n");
		return;
	}
	Product prod;
	int found = 0;
	printf("\nReading products from the file:\n");
	printf("-----------------------------------------------------");
	printf("%-15s%-20s%-9s%-8s\n", "Product ID", "Product Name", "Price", "Quantity");
	printf("-----------------------------------------------------");
	while (fread(&prod, sizeof(Product), 1, fp) == 1) {
		printf("%-15d%-20s%-9.2f%-8d\n", prod.product_id, prod.product_name, prod.price, prod.quantity);
		found = 1;
	}
	printf("-----------------------------------------------------");
	fclose(fp);
	if (found == 0) {
		printf("File not found!\n");
	}
}

void modifyProducts() {
	int id, found = 0;
	printf("Enter the Product ID to modify: ");
	if (scanf("%d", &id) != 1) {
		printf("Invalid input.\n");
		while (getchar() != '\n');
		return;
	}
	FILE *fp = fopen(FILENAME, "rb+");
	if (fp == NULL) {
		printf("File error. File not found!\n");
		return;
	}
	Product prod;
	long pos;
	while (fread(&prod, sizeof(Product), 1, fp) == 1) {
		if (prod.product_id == id) {
			found = 1;
			printf("Product found. Enter new details:\n");
			fflush(stdin);
			printf("New Product Name: ");
			scanf("%[^\n]", &prod.product_name);
			printf("New Price: ");
			while (scanf("%f", &prod.price) != 1 || prod.price < 0) {
				printf("Invalid price. Please enter again: ");
				while (getchar() != '\n');
			}
			pos = ftell(fp) - sizeof(Product);
			fseek(fp, pos, SEEK_SET);
			fwrite(&prod, sizeof(Product), 1, fp);
			printf("Product updated successfully.\n");
			fclose(fp);
			return;
		}
	}
	fclose(fp);
	if (found == 0) {
		printf("Product ID %d not found.\n", id);
	}
}

void removeProducts() {
	int id, found = 0;
	printf("Enter the Product ID to remove: ");
	if (scanf("%d", &id) != 1) {
		printf("Invalid input!\n");
		while (getchar() != '\n');
		return;
	}
	FILE *fp = fopen(FILENAME, "rb");
	if (fp == NULL) {
		printf("File not found.\n");
		return;
	}
	FILE *temp = fopen("temp.bin", "wb");
	if (temp == NULL) {
		printf("File error. Cannot create temporary file.\n");
		fclose(fp);
		return;
	}
	Product prod;
	while (fread(&prod, sizeof(Product), 1, fp) == 1) {
		if (prod.product_id == id) {
			found = 1;
		} else {
			fwrite(&prod, sizeof(Product), 1, temp);
		}
	}
	fclose(fp);
	fclose(temp);
	if (found == 0) {
		remove("temp.bin");
		printf("Product with ID %d is not found.\n", id);
	} else {
		remove(FILENAME);
		rename("temp.bin", FILENAME);
		printf("Product with ID %d removed successfully.\n", id);
	}
}

int checkExist(int id) {
	FILE *fp = fopen(FILENAME, "rb");
	if (fp == NULL) {
		return 1;
	}
	Product prod;
	while (fread(&prod, sizeof(Product), 1, fp) == 1) {
		if (prod.product_id == id) {
			fclose(fp);
			return 0;
		}
	}
	fclose(fp);
	return 1;
}