#include <stdio.h>
#include <string.h>
#include "atm.h"

int login() {
    char correct_pin[] = "1234";
    char pin[10];
    int attempts = 0;
    int max_attempts = 3;

    while (attempts < max_attempts) {
        printf("Enter PIN: ");
        scanf("%9s", pin);

        if (strcmp(pin, correct_pin) == 0) {
            printf("Login successful!\n\n");
            return 1;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts left: %d\n", max_attempts - attempts);
        }
    }

    printf("Too many incorrect attempts. Account locked.\n");
    return 0;
}


