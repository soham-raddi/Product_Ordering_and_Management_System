// Declaring libraries 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the Product structure
typedef struct {
    int id;
    char name[100];
    float price;
    int qty;
    int qty_initial;
} Product;

// Defining the Admin structure 
typedef struct {
    char username[50];
    char password[50];
} Admin;

// Function Prototypes
void addProduct(Product products[] , int *productCount);
void displayProduct(Product products[] , int productCount);
void orderProduct(Product products[] , int productCount);
void viewOrdered(Product products[] , int productCount);
void removeProduct(Product products[] , int *productCount);
int authenticateAdmin(Admin admin);

// Function to add products
// admin function 
void addProduct(Product products[], int *productCount) 
{
	
    Product product;
    
    // getting product details from the admin
    printf("\nProduct Name : ");
    scanf("%s" , product.name);
    
    printf("Product ID : ");
    scanf("%d" , &product.id);
    
    printf("Product Price : ");
    scanf("%f" , &product.price);
    
    printf("Product Quantity : ");
    scanf("%d" , &product.qty);
    
    // to store the inital quantity of the product
    product.qty_initial = product.qty;
    
    // adding product to the array
    products[*productCount] = product;
    (*productCount)++;
    
    printf("\n**Product Added Successfully**\n");
}

// Function to remove products
// admin function 
void removeProduct(Product products[], int *productCount) 
{
	// intitialising variables
    int prodid;
    int item = 0;
    int i , j;
    
    // if no products are available to remove
    if (*productCount == 0) 
	{
        printf("No available products to remove.\n");
        return;
    }
    
    printf("Enter the product ID to be removed : ");
    scanf("%d" , &prodid);
    
    // searching for the product in the product array
    for (i = 0 ; i < *productCount ; i++) 
	{
        if (products[i].id == prodid) 
		{
            for ( j = i ; j < *productCount - 1 ; j++) 
			{
                products[j] = products[j + 1];
            }
            (*productCount)--;									// decrements to reflect about the removal
            item = 1;
            printf("Product with ID %d removed.\n", prodid);
            break;
        }
    }
    
    // product id not found 
    if (!item) 
	{
        printf("\nProduct with ID %d not found.\n", prodid);
    }
}

// Function to display products
void displayProduct(Product products[], int productCount) 
{	
    int i;
    
    // to check if any products are available
    if (productCount == 0) 
	{
        printf("\nNo Products Available.\n");
        return;
    }
    
    // to display products
    printf("\nProduct ID\tProduct Name\tPrice\tQuantity\n");
    for (i = 0 ; i < productCount ; i++) 
	{
        printf("%02d\t\t%s\t\t%.2f\t%d\n", products[i].id , products[i].name , products[i].price , products[i].qty);
    }
    printf("\n");
}

// Function to order products
void orderProduct(Product products[] , int productCount) 
{
	// declaring variables for the function 
    int prodid;
    int quantity;
    int i;
    
    printf("Enter Product ID to place order : ");
    scanf("%d" , &prodid);
    
    printf("Enter Quantity : ");
    scanf("%d" , &quantity);
    
    for (i = 0 ; i < productCount ; i++) 
	{
		// checks the product id in the product array
        if (products[i].id == prodid)
		{
			// checks if the product is available in sufficient quantity
            if (products[i].qty >= quantity) 
			{
                printf("\nOrder Placed Successfully.\n");
                products[i].qty -= quantity;
            } 
			
			// if the product is not available in sufficient quantity
			else
			{
                printf("**The product is not available in sufficient quantity.**\n");
            }
            return;
        }
    }
    printf("\nProduct Not available.\n");
}

// Function to authenticate admin
int authenticateAdmin(Admin admin) 
{
	
	// declaring authenticating variables for the admin
    char username[50], password[50];
    
    printf("\n*****Admin Login*****\n");
    printf("Username : ");
    scanf("%s" , username);
    
    printf("Password : ");
    scanf("%s" , password);
    
    // to check if the entered username and password match the pre defined admin credentials
    if (strcmp(admin.username , username) == 0 && strcmp(admin.password , password) == 0) 
    
	{
        return 1; 											// authentication successful
    } 
	
	else 
	
	{
        return 0; 											// authentication failed
    }
}

// Function to view ordered products
void viewOrdered(Product products[] , int productCount) 
{
	
	// declaring variables for the function 
    int i;
    int flag = 0;
    int ordered_qty;
	
	//to display ordered products
    printf("\nOrdered Products:\n");
    printf("\nProduct ID\tProduct Name\tPrice\tQuantity\n");

    for (i = 0 ; i < productCount ; i++) 
	{
		// to calculate the quantity ordered
        ordered_qty = products[i].qty_initial - products[i].qty; 
        
        // to check if the quantity of ordered products is greater than 0
        if (ordered_qty > 0) 
		{
            printf("%02d\t\t%s\t\t%.2f\t%d\n", products[i].id , products[i].name , products[i].price , ordered_qty);
            flag = 1;
            break;
        }
        break;
    }

    if (!flag) 
	{
		// if no products are ordered
        printf("\nNo ordered products.\n");
    }

    printf("\n");
}

// Main Function
int main() 
{
	// declaring variables
    Product products[100];
    int productCount = 0;
    int choice;
    int user;
    
    // initialising admin usename and password
    Admin admin = {"admin" , "password"}; 
    int adminAuthenticated = 0;

    do {
    	
    	// for selecting user type
        printf("Select user type : \n");
        printf("\n1. Admin\n");
        printf("2. Customer\n");
        printf("3. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &user);

		//switch for user
        switch (user) {
        	
        	// case for admin
            case 1:
            	
            	// calling and checking admin authentication function
                adminAuthenticated = authenticateAdmin(admin);
                
                // admin not authenticated
                if (!adminAuthenticated) 
				{
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
                    scanf("%d" , &choice);

					// switch for admin commands
                    switch (choice) {
                    	
                        case 1:
                            addProduct(products, &productCount);
                            break;
                            
                        case 2:
                            displayProduct(products, productCount);
                            break;
                            
                        case 3:
                            removeProduct(products, &productCount);
                            break;
                            
                        case 4:
                            printf("\nExiting admin menu.\n");
                            printf("\n");
                            break;
                            
                        default:
                            printf("Invalid choice.\n");
                            break;
                    }
                } while (choice != 4);
                break;
            
			// case for customer/user  
            case 2:           	
                do {
                	
                    printf("\n=============Customer Menu=============\n");
                    printf("\n1. Display Products\n");
                    printf("2. Place Order\n");
                    printf("3. View Ordered Products\n");
                    printf("4. Exit\n");
                    printf("\nEnter your choice : ");
                    scanf("%d" , &choice);

					// switch for user functions
                    switch (choice) {
                    	
                        case 1:                       	
                            displayProduct(products, productCount);
                            break;
                            
                        case 2:                    	
                            orderProduct(products, productCount);
                            break;
                            
                        case 3:
                        	viewOrdered(products, productCount);
                        	break;
                            
                        case 4:
                            printf("\n=============    Exiting customer menu.    =============\n");
                            printf("\n");
                            break;
                            
                        default:                      	
                            printf("Invalid choice. Please select valid options.\n");
                            break;
                    }
                } while (choice != 4);
                break;
            
            // case for program exit
            case 3:           	
                printf("\n=============    Exiting the program.    =============\n");
                break;
                
            // case for default options
            default:           	
                printf("Invalid choice. Please select valid options.\n");
                break;
        }
    } while (user != 3);
    return 0;
}
