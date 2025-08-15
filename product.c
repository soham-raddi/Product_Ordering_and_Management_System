#include <stdio.h>
#include <string.h>
#include "product.h"

void addProduct(Product products[], int *productCount) {
    Product product;
    printf("\nProduct Name : ");
    scanf("%s", product.name);
    printf("Product ID : ");
    scanf("%d", &product.id);
    printf("Product Price : ");
    scanf("%f", &product.price);
    printf("Product Quantity : ");
    scanf("%d", &product.qty);
    product.qty_initial = product.qty;
    products[*productCount] = product;
    (*productCount)++;
    printf("\n**Product Added Successfully**\n");
}

void removeProduct(Product products[], int *productCount) {
    int prodid, item = 0;
    if (*productCount == 0) {
        printf("No available products to remove.\n");
        return;
    }
    printf("Enter the product ID to be removed : ");
    scanf("%d", &prodid);
    for (int i = 0; i < *productCount; i++) {
        if (products[i].id == prodid) {
            for (int j = i; j < *productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            (*productCount)--;
            item = 1;
            printf("Product with ID %d removed.\n", prodid);
            break;
        }
    }
    if (!item) {
        printf("\nProduct with ID %d not found.\n", prodid);
    }
}

void displayProduct(Product products[], int productCount) {
    if (productCount == 0) {
        printf("\nNo Products Available.\n");
        return;
    }
    printf("\nProduct ID\tProduct Name\tPrice\tQuantity\n");
    for (int i = 0; i < productCount; i++) {
        printf("%02d\t\t%s\t\t%.2f\t%d\n",
               products[i].id, products[i].name,
               products[i].price, products[i].qty);
    }
    printf("\n");
}