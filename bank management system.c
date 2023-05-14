#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS
#define MAX_CUSTOMERS 10    // maximum number of customers in the bank system

struct customer {
    int account_number;
    char name[50];
    float balance;
};

struct customer customers[MAX_CUSTOMERS];    // array to store all customer#define MAX_CUSTOMERS 100 // maximum number of customers that can be stored

struct customer{
  int id;
  float balance;
}

struct customer customers[MAX_CUSTOMERS]; // array to store all the customers
int num_customers = 0; // current number of customers in the array

// function to create a new customer account
void create_account() {
  int id;
  float balance;
  
  // get user input for account details
  printf("Enter customer ID: ");
  scanf("%d", &id);
  
  // check if customer already exists
  for (int i = 0; i < num_customers; i++) {
    if (customers[i].id == id) {
      printf("Error: customer already exists.\n");
      return;
    }
  }
  
  printf("Enter starting balance: ");
  scanf("%f", &balance);
  
  // add new customer to the array
  customers[num_customers].id = id;
  customers[num_customers].balance = balance;
  num_customers++;
  
  printf("New account created.\n");
}

// function to deposit money into a customer's account
void deposit() {
  int id;
  float amount;
  
  // get user input for account details
  printf("Enter customer ID: ");
  scanf("%d", &id);
  
  // find the customer in the array
  int index = -1;
  for (int i = 0; i < num_customers; i++) {
    if (customers[i].id == id) {
      index = i;
      break;
    }
  }
  
  if (index == -1) {
    printf("Error: customer not found.\n");
    return;
  }
  
  printf("Enter amount to deposit: ");
  scanf("%f", &amount);
  
  // update the customer's balance
  customers[index].balance += amount;
  
  printf("Deposit successful. New balance is %.2f.\n", customers[index].balance);
}

// function to withdraw money from a customer's account
void withdraw() {
  int id;
  float amount;
  
  // get user input for account details
  printf("Enter customer ID: ");
  scanf("%d", &id);
  
  // find the customer in the array
  int index = -1;
  for (int i = 0; i < num_customers; i++) {
    if (customers[i].id == id) {
      index = i;
      break;
    }
  }
  
  if (index == -1) {
    printf("Error: customer not found.\n");
    return;
  }
  
  printf("Enter amount to withdraw: ");
  scanf("%f", &amount);
  
  // check if the customer has enough balance
  if (customers[index].balance < amount) {
    printf("Error: insufficient balance.\n");
    return;
  }
  
  // update the customer's balance
  customers[index].balance -= amount;
  
  printf("Withdrawal successful. New balance is %.2f.\n", customers[index].balance);
}

// function to view a customer's account balance
void view_balance() {
  int id;
  
  // get user input for account details
  printf("Enter customer ID: ");
  scanf("%d", &id);
  
  // find the customer in the array
  int index = -1;
  for (int i = 0; i < num_customers; i++) {
    if (customers[i].id == id) {
      index = i;
      break;
    }
  }
  
  if (index == -1) {
    printf("Error: customer not found.\n");
    return;
  }
  
  printf("Customer %d has a balance of %.2f.\n", customers[index].id, customers[index].balance);
}

// main function to run the bank management system
int main() {
  int choice;
  
  while (1) {
    printf("\nBank Management System\n");
    printf("1. Create account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View balance\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        create_account();
        break;
      case 2:
        deposit();
        break;
      case 3:
        withdraw();
        break;
      case 4:
        view_balance();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }
  
  return 0;
}

