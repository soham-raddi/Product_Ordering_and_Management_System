#ifndef ADMIN_H
#define ADMIN_H
#include "product.h"

typedef struct {
    char username[50];
    char password[50];
} Admin;

int authenticateAdmin(Admin admin);

#endif