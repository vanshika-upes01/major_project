#include <stdio.h>
#include "length.h"
#include "history.h"

void lengthMenu() {
    int choice;
    double input, result;
    
    printf("\n--- LENGTH CONVERSION ---\n");
    printf("1. Meter to Kilometer\n");
    printf("2. Meter to Mile\n");
    printf("3. Meter to Foot\n");
    printf("4. Kilometer to Meter\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Enter length value: ");
    scanf("%lf", &input);
    
    switch(choice) {
        case 1:
            result = meterToKilometer(input);
            printf("%.2f m = %.3f km\n", input, result);
            saveToHistory("Length", input, result, "Meter", "Kilometer");
            break;
        case 2:
            result = meterToMile(input);
            printf("%.2f m = %.4f miles\n", input, result);
            saveToHistory("Length", input, result, "Meter", "Mile");
            break;
        case 3:
            result = meterToFoot(input);
            printf("%.2f m = %.2f ft\n", input, result);
            saveToHistory("Length", input, result, "Meter", "Foot");
            break;
        case 4:
            result = kilometerToMeter(input);
            printf("%.2f km = %.2f m\n", input, result);
            saveToHistory("Length", input, result, "Kilometer", "Meter");
            break;
    }
}

double meterToKilometer(double meter) {
    return meter / 1000.0;
}

double meterToMile(double meter) {
    return meter / 1609.34;
}

double meterToFoot(double meter) {
    return meter * 3.28084;
}

double kilometerToMeter(double km) {
    return km * 1000.0;
}
