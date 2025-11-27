#include <stdio.h>
#include "temperature.h"
#include "history.h"

// Display temperature conversion submenu
void temperatureMenu() {
    int choice;
    double input, result;
    
    printf("\n--- TEMPERATURE CONVERSION ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Enter temperature value: ");
    scanf("%lf", &input);
    
    // Perform conversion based on user choice
    switch(choice) {
        case 1:
            result = celsiusToFahrenheit(input);
            printf("%.2f°C = %.2f°F\n", input, result);
            saveToHistory("Temperature", input, result, "Celsius", "Fahrenheit");
            break;
        case 2:
            result = celsiusToKelvin(input);
            printf("%.2f°C = %.2fK\n", input, result);
            saveToHistory("Temperature", input, result, "Celsius", "Kelvin");
            break;
        case 3:
            result = fahrenheitToCelsius(input);
            printf("%.2f°F = %.2f°C\n", input, result);
            saveToHistory("Temperature", input, result, "Fahrenheit", "Celsius");
            break;
        case 4:
            result = fahrenheitToKelvin(input);
            printf("%.2f°F = %.2fK\n", input, result);
            saveToHistory("Temperature", input, result, "Fahrenheit", "Kelvin");
            break;
        case 5:
            result = kelvinToCelsius(input);
            printf("%.2fK = %.2f°C\n", input, result);
            saveToHistory("Temperature", input, result, "Kelvin", "Celsius");
            break;
        case 6:
            result = kelvinToFahrenheit(input);
            printf("%.2fK = %.2f°F\n", input, result);
            saveToHistory("Temperature", input, result, "Kelvin", "Fahrenheit");
            break;
    }
}

// Conversion formulas
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}
