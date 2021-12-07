#include <stdio.h>
#include <stdlib.h>
#include "constants.h"


#define CLEAR_SCREEN system("clear");
#define HAULT printf("Press enter to return to the main screen\n"); scanf("%c", &garbage);


int main(int argc, char** argv) {
    int tempInputs[3];
    int input = 0;
    double out = 0;
    char garbage;

    while (input != 8) {
        do {
            CLEAR_SCREEN

            printf("1) Ohm's law\n");
            printf("2) Thermal loss\n");
            printf("3) Power consumption\n");
            printf("4) Needed resistor\n");
            printf("5) Serial resistor resistance\n");
            printf("6) Parallel resistor resistance\n");
            printf("7) Resistor colour code calculator\n");
            printf("8) Exit\n");

            printf("\n>>> ");
            scanf("%i", &input);
            scanf("%c", &garbage);
        } while (input == 0 || input > 8);

        switch (input) 
        {
            case (1):
                CLEAR_SCREEN

                printf("1) Resistance\n");
                printf("2) Amperage\n");
                printf("3) Voltage\n");

                printf("\n>>> ");
                scanf("%i", &input);
                scanf("%c", &garbage);

                switch (input)
                {
                    case (1):
                        CLEAR_SCREEN

                        printf("Voltage\n>>> ");
                        scanf("%i", &tempInputs[0]);
                        scanf("%c", &garbage);

                        printf("\nAmperage\n>>> ");
                        scanf("%i", &tempInputs[1]);
                        scanf("%c", &garbage);

                        printf("\nResistance: %.2lf\n\n", RESISTANCE(tempInputs[0], tempInputs[1]));
                        HAULT

                        break;
                    
                    case (2):
                        CLEAR_SCREEN

                        printf("Voltage\n>>> ");
                        scanf("%i", &tempInputs[0]);
                        scanf("%c", &garbage);

                        printf("\nResistance\n>>> ");
                        scanf("%i", &tempInputs[1]);
                        scanf("%c", &garbage);

                        printf("\nAmperage: %.2lf\n\n", AMPERAGE(tempInputs[0], tempInputs[1]));
                        HAULT

                        break;
                    
                    case (3):
                        CLEAR_SCREEN

                        printf("Resistance\n>>> ");
                        scanf("%i", &tempInputs[0]);
                        scanf("%c", &garbage);

                        printf("\nAmperage\n>>> ");
                        scanf("%i", &tempInputs[1]);
                        scanf("%c", &garbage);

                        printf("\nVoltage: %.2lf\n\n", VOLTS(tempInputs[0], tempInputs[1]));
                        HAULT

                        break;
                    
                    default:
                        HAULT

                        break;
                }

                break;
            
            case (2):
                CLEAR_SCREEN

                printf("Resistance\n>>> ");
                scanf("%i", &tempInputs[0]);
                scanf("%c", &garbage);

                printf("\nAmperage\n>>> ");
                scanf("%i", &tempInputs[1]);
                scanf("%c", &garbage);

                printf("\nThermal loss: %.2lf\n\n", THERMAL_LOSS(tempInputs[0], tempInputs[1]));
                HAULT

                break;
            
            case (3):
                CLEAR_SCREEN

                printf("Voltage\n>>> ");
                scanf("%i", &tempInputs[0]);
                scanf("%c", &garbage);

                printf("\nAmperage\n>>> ");
                scanf("%i", &tempInputs[1]);
                scanf("%c", &garbage);

                printf("\nTime (seconds)\n>>> ");
                scanf("%i", &tempInputs[2]);
                scanf("%c", &garbage);
                
                printf("\nPower consuptions (Watts): %i\n\n", POWER_CONSUMPTION(tempInputs[0], tempInputs[1], tempInputs[2]));
                HAULT

                break;
            
            case (4): // needed resistor
                CLEAR_SCREEN

                printf("Voltage source\n>>> ");
                scanf("%i", &tempInputs[0]);
                scanf("%c", &garbage);

                printf("\nForwards voltage\n>>> ");
                scanf("%i", &tempInputs[1]);
                scanf("%c", &garbage);

                printf("\nAmperage\n>>> ");
                scanf("%i", &tempInputs[2]);
                scanf("%c", &garbage);
                
                printf("\nResistor needed: %.2lf ohms\n\n", NEEDED_RESISTOR(tempInputs[0], tempInputs[1], tempInputs[2]));
                HAULT

                break;
            
            case (5):
                CLEAR_SCREEN

                out = 0;
                serialResistance(getArrayInput("Resistor: ", 0), &out);
                printf("Resistance: %.2lf\n", out);
                HAULT

                break;
            
            case (6):
                CLEAR_SCREEN

                out = 0;
                parallelResistance(getArrayInput("Resistor: ", 0), &out);
                printf("Resistance: %.2lf\n", out);
                HAULT

                break;
            
            case (7):
                CLEAR_SCREEN

                printf("Resistance: %.2lf\n", resistorCalculator());
                HAULT

                break;
            
            default:
                break;
        }
    }

    return 0;
}