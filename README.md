# Billing System
### Description
<p align="justify">This C++ program is designed to manage a simple billing system for a store. It allows for creating, modifying, and deleting product entries, as well as generating invoices for customers. The program stores product information in a file and reads from it as needed to handle transactions.</p>

## Features
- <b>Product Management:</b> Create, display, modify, and delete products.
- <b>Billing:</b> Generate invoices with product details and total amount.
<b>Persistent Storage:</b> Product information is stored persistently in a text file (products.txt), allowing for data retention between sessions.

## Getting Started
### Prerequisites
- C++ Compiler (e.g., g++, clang, MSVC)
- Development Environment (Optional): Visual Studio Code or any C++ IDE


## Compiling and Running
### Windows
#### 1 Compile the Program:
- Open Command Prompt.
- Navigate to the directory containing your program.
- Run the following command:
```
g++ -o BillingSystem your_file_name.cpp
```


#### 2 Run the Program:
- In the Command Prompt, execute:
```
BillingSystem.exe
```

## Usage
Upon running, the program will display an introductory screen and then present the user with a main menu offering options for different operations:

### 1 Customer:
- Process new invoices.
- Add items to the invoice using product codes and quantities.
- View and print the final invoice.

### 2 Administrator:
- Add new products to the system.
- Display all products.
- Modify or delete existing products.
- To navigate through the program, users will input their choices as prompted on the console.

## File Structure
- <b>products.txt:</b> Stores the details of the products in the system.
- <b>bill.cpp:</b> Contains all the logic for the program including classes and main control flow.