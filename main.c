#include <stdio.h>
#include <string.h>

int login() {
    char correct_pin[] = "1234";
    char pin[10];
    int attempts = 0;
    int max_attempts = 3;

    while (attempts < max_attempts) {
        printf("Enter PIN: ");
        scanf("%s", pin);

        if (strcmp(pin, correct_pin) == 0) {
            printf("Login successful!\n\n");
            return 1;   // success
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts left: %d\n", max_attempts - attempts);
        }
    }

    printf("Too many incorrect attempts. Account locked.\n");
    return 0;   // failed login
}

int main() {
    float balance = 1000.00;   // starting balance
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
                if (amount <= balance && amount > 0) {
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
