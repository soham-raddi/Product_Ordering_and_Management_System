#include <stdio.h>
#include "product.h"   // Defines the Product struct
#include "customer.h"

void orderProduct(Product products[], int productCount) {
    int prodid, quantity;
    printf("Enter Product ID to place order : ");
    scanf("%d", &prodid);
    printf("Enter Quantity : ");
    scanf("%d", &quantity);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == prodid) {
            if (products[i].qty >= quantity) {
                printf("\nOrder Placed Successfully.\n");
                products[i].qty -= quantity;
            } else {
                printf("**The product is not available in sufficient quantity.**\n");
            }
            return;
        }
    }
    printf("\nProduct Not available.\n");
}

void viewOrdered(Product products[], int productCount) {
    int flag = 0;
    printf("\nOrdered Products:\n");
    printf("\nProduct ID\tProduct Name\tPrice\tQuantity\n");

    for (int i = 0; i < productCount; i++) {
        int ordered_qty = products[i].qty_initial - products[i].qty;
        if (ordered_qty > 0) {
            printf("%02d\t\t%s\t\t%.2f\t%d\n",
                   products[i].id, products[i].name,
                   products[i].price, ordered_qty);
            flag = 1;
        }
    }
    if (!flag) {
        printf("\nNo ordered products.\n");
    }
    printf("\n");
}
