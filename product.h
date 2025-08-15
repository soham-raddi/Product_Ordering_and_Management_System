#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct {
    int id;
    char name[100];
    float price;
    int qty;
    int qty_initial;
} Product;

void addProduct(Product products[], int *productCount);
void removeProduct(Product products[], int *productCount);
void displayProduct(Product products[], int productCount);

#endif
