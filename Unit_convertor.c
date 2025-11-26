#include <stdio.h>

int main() {
    int choice;
    float value, result;

    do {
        printf("\n---- BASIC UNIT CONVERTER ----\n");
        printf("1. Meter to Centimeter\n");
        printf("2. Kilogram to Gram\n");
        printf("3. Celsius to Fahrenheit\n");
        printf("4. Seconds to Minutes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 5) {
            printf("Exiting... Thank you!\n");
            break;
        }

        printf("Enter value: ");
        scanf("%f", &value);

        switch(choice) {
            case 1: result = value * 100; printf("Result: %.2f cm\n", result); break;
            case 2: result = value * 1000; printf("Result: %.2f g\n", result); break;
            case 3: result = (value * 9/5) + 32; printf("Result: %.2f F\n", result); break;
            case 4: result = value / 60; printf("Result: %.2f min\n", result); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}
