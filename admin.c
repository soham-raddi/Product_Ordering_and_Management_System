#include <stdio.h>
#include <string.h>
#include "admin.h"

int authenticateAdmin(Admin admin) {
    char username[50], password[50];
    printf("\n*****Admin Login*****\n");
    printf("Username : ");
    scanf("%s", username);
    printf("Password : ");
    scanf("%s", password);
    if (strcmp(admin.username, username) == 0 &&
        strcmp(admin.password, password) == 0) {
        return 1;
    }
    return 0;
}