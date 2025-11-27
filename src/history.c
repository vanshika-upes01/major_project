#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

// Global variables for history management
static ConversionRecord *history = NULL;
static int historyCount = 0;
static int historyCapacity = 10;

// Save conversion to history using dynamic memory allocation
void saveToHistory(const char* type, double input, double output, 
                   const char* unit1, const char* unit2) {
    // Allocate memory on first use
    if (history == NULL) {
        history = (ConversionRecord*)malloc(historyCapacity * sizeof(ConversionRecord));
        if (history == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
    }
    
    // Reallocate if capacity exceeded
    if (historyCount >= historyCapacity) {
        historyCapacity *= 2;
        history = (ConversionRecord*)realloc(history, historyCapacity * sizeof(ConversionRecord));
        if (history == NULL) {
            printf("Memory reallocation failed!\n");
            return;
        }
    }
    
    // Store conversion record
    strcpy(history[historyCount].conversionType, type);
    history[historyCount].inputValue = input;
    history[historyCount].outputValue = output;
    strcpy(history[historyCount].unit1, unit1);
    strcpy(history[historyCount].unit2, unit2);
    historyCount++;
}

// Display all conversion history
void displayHistory() {
    if (historyCount == 0) {
        printf("\nNo conversion history available.\n");
        return;
    }
    
    printf("\n--- CONVERSION HISTORY ---\n");
    for (int i = 0; i < historyCount; i++) {
        printf("%d. %s: %.2f %s = %.2f %s\n", 
               i+1,
               history[i].conversionType,
               history[i].inputValue,
               history[i].unit1,
               history[i].outputValue,
               history[i].unit2);
    }
}

// Free dynamically allocated memory
void freeHistory() {
    if (history != NULL) {
        free(history);
        history = NULL;
    }
}
