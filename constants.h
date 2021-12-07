#define RESISTANCE(U, I) (float) U / (float) I
#define VOLTS(R, I) (float) R * (float) I
#define AMPERAGE(U, R) (float) U / (float) R

#define POWER_CONSUMPTION(U, I, t) U * I * t
#define NEEDED_RESISTOR(SRC, FWR, I) ((float) SRC - (float) FWR) / (float) I
#define THERMAL_LOSS(R, I) (float) R * ((float) I * (float) I)


#pragma region declareFuncs

void serialResistance(long int* resistanceValues, double* out);
void parallelResistance(long int* resistanceValues, double* out);
long int* getArrayInput(const char* msg, int endCondition);
double resistorCalculator();
long int power(int num, int exponent);

#pragma endregion declareFuncs


#pragma region funcs

void serialResistance(long int* resistanceValues, double* out) {
    int offset = 0;

    while (*(resistanceValues + offset) != 0) {
        *out += *(resistanceValues + offset);
        offset++;
    }
}


void parallelResistance(long int* resistanceValues, double* out) {
    int offset = 0;

    do {
        if (*(resistanceValues + offset) == 0) {
            if (offset == 2) {
                *out = (*resistanceValues * *(resistanceValues + 1)) / ((*resistanceValues + *(resistanceValues + 1)));
            } else {
                offset = 0;

                while (*(resistanceValues + offset) != 0) {
                    *out += 1 / (float) *(resistanceValues + offset);
                    offset++;
                }
            }
        }

        offset++;
    } while (*(resistanceValues + offset - 1) != 0);
}


long int* getArrayInput(const char* msg, int endCondition) {
    long int* out = malloc(sizeof(long int));
    int offset = 0;
    char garbage;

    do {
        printf("%s", msg);
        scanf("%li", (out + offset));
        scanf("%c", &garbage);

        out = realloc(out, sizeof(long int) * (offset + 2));
        offset++;
    } while(*(out + offset - 1) != endCondition);

    return out;
}


double resistorCalculator() {
    unsigned long int resistanceRaw = 0;
    double resistance;
    char codes[4], garbage;

    printf("Black 0 / Brown 1 / Red 2 / Orange 3 / Yellow 4\n");
    printf("Green 5 / Blue 6 / Violet 7 / Gray 8 / White 9\n");
    printf("Gold g / Silver s\n");
    printf("\nEnter only 4 values\n\n");

    for (int i = 0; i < 4; i++) {
        printf("%ist band\n>>> ", (i + 1));

        scanf("%c", &codes[i]);
        scanf("%c", &garbage);
        printf("\n");

        codes[i] -= '0';
    }

    if (codes[3] + '0' == 'g') {
        return (codes[0] * 100 + codes[1] * 10 + codes[2]) * 0.1;
    } else if (codes[3] + '0' == 's') {
        return (codes[0] * 100 + codes[1] * 10 + codes[2]) * 0.01;
    } else {
        return (codes[0] * 100 + codes[1] * 10 + codes[2]) * power(10, codes[3]);
    }
}

long int power(int num, int exponent) {
    if (exponent == 0)
        return 1;


    long int toReturn = num;

    for (int i = 1; i < exponent; i++) {
        toReturn *= num;
    }

    return toReturn;
}

#pragma endregion funcs