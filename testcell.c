#include <stdio.h>

#define MAX_VOLTAGE 4.2
#define MAX_CURRENT 2.0
#define MIN_CURRENT 0.1
#define MAX_TEMPERATURE 45.0
#define MIN_TEMPERATURE 0.0
#define TARGET_TEMPERATURE 40.0

typedef struct {
    float voltage;
    float current;
    float temperature;
} Battery;

void balanceCells(Battery cells[], int size) {
    float totalVoltage = 0;
    for (int i = 0; i < size; i++) {
        totalVoltage += cells[i].voltage;
    }
    float averageVoltage = totalVoltage / size;
    for (int i = 0; i < size; i++) {
        cells[i].voltage = averageVoltage;
    }
}

void regulateTemperature(Battery *battery) {
    if (battery->temperature > TARGET_TEMPERATURE) {
        printf("Cooling down: Temperature = %.2f°C\n", battery->temperature);
        while (battery->temperature > TARGET_TEMPERATURE) {
            battery->temperature -= 1.0; // Simulate cooling
        }
    } else if (battery->temperature < MIN_TEMPERATURE) {
        printf("Heating up: Temperature = %.2f°C\n", battery->temperature);
        while (battery->temperature < MIN_TEMPERATURE) {
            battery->temperature += 1.0; // Simulate heating
        }
    }
}

int main() {
    Battery cells[] = {
        {4.1, 1.5, 40.0},
        {4.0, 1.5, 42.0},
        {4.2, 1.5, 38.0},
        {4.1, 1.5, 41.0}
    };
    int size = sizeof(cells) / sizeof(cells[0]);
    printf("Starting cell balancing...\n");
    balanceCells(cells, size);
    printf("Balanced cells:\n");
    for (int i = 0; i < size; i++) {
        printf("Cell %d: Voltage = %.2f V, Temperature = %.2f°C\n", i, cells[i].voltage, cells[i].temperature);
    }

    printf("Regulating temperature...\n");
    for (int i = 0; i < size; i++) {
        regulateTemperature(&cells[i]);
        printf("Cell %d: Voltage = %.2f V, Temperature = %.2f°C\n", i, cells[i].voltage, cells[i].temperature);
    }

    return 0;
}