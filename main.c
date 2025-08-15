#include <stdio.h>
#include "product.h"
#include "admin.h"
#include "customer.h"

int main() {
    Product products[100];
    int productCount = 0;
    int choice, user;
    Admin admin = {"admin", "password"};
    int adminAuthenticated = 0;

    do {
        printf("Select user type : \n");
        printf("\n1. Admin\n");
        printf("2. Customer\n");
        printf("3. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &user);

        switch (user) {
            case 1:
                adminAuthenticated = authenticateAdmin(admin);
                if (!adminAuthenticated) {
                    printf("Admin authentication failed. Exiting to user menu.\n");
                    break;
                }
                do {
                    printf("\n=============Admin Menu=============\n");
                    printf("\n1. Add a product\n");
                    printf("2. View products\n");
                    printf("3. Remove a product\n");
                    printf("4. Exit\n");
                    printf("\nEnter your choice : ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1: addProduct(products, &productCount); break;
                        case 2: displayProduct(products, productCount); break;
                        case 3: removeProduct(products, &productCount); break;
                        case 4: printf("\nExiting admin menu.\n"); break;
                        default: printf("Invalid choice.\n"); break;
                    }
                } while (choice != 4);
                break;

            case 2:
                do {
                    printf("\n=============Customer Menu=============\n");
                    printf("\n1. Display Products\n");
                    printf("2. Place Order\n");
                    printf("3. View Ordered Products\n");
                    printf("4. Exit\n");
                    printf("\nEnter your choice : ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1: displayProduct(products, productCount); break;
                        case 2: orderProduct(products, productCount); break;
                        case 3: viewOrdered(products, productCount); break;
                        case 4: printf("\nExiting customer menu.\n"); break;
                        default: printf("Invalid choice.\n"); break;
                    }
                } while (choice != 4);
                break;

            case 3:
                printf("\nExiting the program.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (user != 3);

    return 0;
}