# Product Ordering and Management System

A simple C-based inventory management program that allows admins to manage products and customers to place orders.  
This project demonstrates modular C programming, file handling, and basic data structures.

---

## Features

### Admin
- Add new products
- View all products
- Update product details
- Delete products

### Customer
- View available products
- Place an order
- View order details

---

## Project Structure

```
Product_Ordering_and_Management_System/
│
├── main.c          # Entry point of the program
├── product.c       # Product management functions
├── admin.c         # Admin-specific functionality
├── customer.c      # Customer-specific functionality
├── product.h       # Header for product functions
├── admin.h         # Header for admin functions
├── customer.h      # Header for customer functions
├── Makefile        # Build instructions
└── README.md       # Project documentation
```

---

## Installation & Compilation

### 1. Install GCC and Make
- **Windows**: Install [MinGW-w64](https://www.mingw-w64.org/) and ensure `gcc` & `mingw32-make` are in PATH.
- **Linux/macOS**: Install GCC & Make via package manager:
  ```bash
  sudo apt install build-essential   # Ubuntu/Debian
  sudo dnf groupinstall "Development Tools"   # Fedora
  brew install gcc make              # macOS (Homebrew)
  ```

### 2. Clone the Repository
```
git clone https://github.com/soham-raddi/Product_Ordering_and_Management_System.git
cd Product_Ordering_and_Management_System
```

### 3. Compile the Program
```bash
mingw32-make    # Windows
make            # Linux/macOS
```

### 4. Run the Program
```bash
./inventory     # Linux/macOS
inventory.exe   # Windows
```

---

## Usage

1. When the program starts, choose whether to log in as:
   - **Admin** → Manage inventory
   - **Customer** → Browse products & place orders

2. Follow the menu prompts:
   - Enter product details when prompted
   - For customers, enter product ID and quantity to order

---

## Example Run

```
===== Product Ordering and Management System =====
1. Admin
2. Customer
3. Exit
Enter choice: 1

=== Admin Menu ===
1. Add Product
2. View Products
3. Update Product
4. Delete Product
5. Logout
Enter choice: 1

Enter Product ID: 101
Enter Product Name: Laptop
Enter Price: 55000
Enter Quantity: 10
Product added successfully!
```

---

## Technologies Used
- Language: C
- Compiler: GCC (MinGW for Windows)
- Build Tool: Makefile
- Concepts: Modular Programming, File Handling, Structs

---