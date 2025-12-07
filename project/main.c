#include <stdio.h>
#include "atm.h"

int main() {
    float balance = 1000.00;
    int choice;
    float amount;

    if (!login()) {
        return 0;
    }

    while (1) {
        printf("=== ATM MENU ===\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Your current balance is: Ksh %.2f\n\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful! New balance: Ksh %.2f\n\n", balance);
                } else {
                    printf("Invalid deposit amount.\n\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Withdrawal successful! New balance: Ksh %.2f\n\n", balance);
                } else {
                    printf("Insufficient balance or invalid amount.\n\n");
                }
                break;

            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}
