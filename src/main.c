#include <stdio.h>
#include <stdlib.h>
#include "converter.h"
#include "temperature.h"
#include "length.h"
#include "weight.h"
#include "history.h"

int main() {
    int choice;
    
    printf("  ADVANCED UNIT CONVERTER SYSTEM\n");
    
    // Main program loop
    do {
        displayMainMenu();
        choice = getValidChoice(0, 4);
        
        // Switch case to handle menu selection
        switch(choice) {
            case 1:
                temperatureMenu();  // Call temperature conversion module
                break;
            case 2:
                lengthMenu();  // Call length conversion module
                break;
            case 3:
                weightMenu();  // Call weight conversion module
                break;
            case 4:
                displayHistory();  // Display conversion history
                break;
            case 0:
                printf("\nThank you for using Unit Converter!\n");
                break;
        }
        
    } while(choice != 0);
    
    freeHistory();  // Free dynamically allocated memory
    return 0;
}

// Function to display main menu
void displayMainMenu() {
    printf("\n--- MAIN MENU ---\n");
    printf("1. Temperature Conversion\n");
    printf("2. Length Conversion\n");
    printf("3. Weight Conversion\n");
    printf("4. View Conversion History\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

// Function to validate user input within a range
int getValidChoice(int min, int max) {
    int choice;
    
    // Input validation loop
    while(scanf("%d", &choice) != 1 || choice < min || choice > max) {
        printf("Invalid input! Please enter a number between %d and %d: ", min, max);
        while(getchar() != '\n');  // Clear input buffer
    }
    
    return choice;
}
