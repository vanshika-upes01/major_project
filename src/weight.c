#include <stdio.h>
#include "weight.h"
#include "history.h"

void weightMenu() {
    int choice;
    double input, result;
    
    printf("\nWEIGHT CONVERSION\n");
    printf("1. Kilogram to Gram\n");
    printf("2. Kilogram to Pound\n");
    printf("3. Gram to Kilogram\n");
    printf("4. Pound to Kilogram\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Enter weight value: ");
    scanf("%lf", &input);
    
    switch(choice) {
        case 1:
            result = kgToGram(input);
            printf("%.2f kg = %.2f g\n", input, result);
            saveToHistory("Weight", input, result, "Kilogram", "Gram");
            break;
        case 2:
            result = kgToPound(input);
            printf("%.2f kg = %.2f lb\n", input, result);
            saveToHistory("Weight", input, result, "Kilogram", "Pound");
            break;
        case 3:
            result = gramToKg(input);
            printf("%.2f g = %.3f kg\n", input, result);
            saveToHistory("Weight", input, result, "Gram", "Kilogram");
            break;
        case 4:
            result = poundToKg(input);
            printf("%.2f lb = %.2f kg\n", input, result);
            saveToHistory("Weight", input, result, "Pound", "Kilogram");
            break;
    }
}

double kgToGram(double kg) {
    return kg * 1000.0;
}

double kgToPound(double kg) {
    return kg * 2.20462;
}

double gramToKg(double gram) {
    return gram / 1000.0;
}

double poundToKg(double pound) {
    return pound / 2.20462;
}
