#ifndef HISTORY_H
#define HISTORY_H

// Structure to store conversion history
typedef struct {
    char conversionType[50];
    double inputValue;
    double outputValue;
    char unit1[20];
    char unit2[20];
} ConversionRecord;

// Function declarations for history management
void saveToHistory(const char* type, double input, double output, 
                   const char* unit1, const char* unit2);
void displayHistory();
void freeHistory();

#endif
