#include <iostream>
#include "GilMotivation.h"
#include "ThirdCalcuation.h"

// Constants
const int MIN_YC = 0;
const int MAX_YC = 255;
const int MIN_GIL = 1;
const int MAX_GIL = 999999999;
const int MAX_ZL = 3;
const int MIN_ZL = 1;
const int ZANMATO_GUARANTEED_THRESHOLD = 80;
const int ZANMATO_IMPOSSIBLE_THRESHOLD = 16;
const int ZANMATO_MAX_ROLL = 64;

// Function prototypes
int getUserInput(const std::string& prompt, int minValue, int maxValue);
int calculateZanmatoChance(int yc, int gil, int od, int zl);

int main() {
    int yc = getUserInput("First, what is Yojimbo's compatibility value (0-255)? ", MIN_YC, MAX_YC);
    int gil = getUserInput("Okay, I need to know how much gil you've paid to him (1-999999999): ", MIN_GIL, MAX_GIL);

    int pay = gilMotivation(gil);
    int fc = yc / 4 + pay;

    int od = getUserInput("Great! We need to check whether Yojimbo's Overdrive bar is full. If it is, type 1. Else, type any number: ", 0, 1);
    int sc = fc + (od == 1 ? 20 : 0);

    int zl = getUserInput("Now, we need to determine the enemy's Zanmato Level. If it's 1, 2, or 3, then type 1. Otherwise, type any number: ", MIN_ZL, MAX_ZL);

    int zanmatoChance = calculateZanmatoChance(yc, gil, od, zl);

    if (zanmatoChance >= ZANMATO_GUARANTEED_THRESHOLD) {
        std::cout << "Zanmato is guaranteed!";
    }
    else if (zanmatoChance <= ZANMATO_IMPOSSIBLE_THRESHOLD) {
        std::cout << "No chance of Zanmato!";
    }
    else {
        std::cout << "Chance of Zanmato is = " << zanmatoChance << "%";
    }

    std::cout << std::endl;
    system("pause");
}

// Function to get validated user input
int getUserInput(const std::string& prompt, int minValue, int maxValue) {
    int input;
    do {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail() || input < minValue || input > maxValue) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    } while (true);
    return input;
}

// Function to calculate Zanmato chance
int calculateZanmatoChance(int yc, int gil, int od, int zl) {
    int pay = gilMotivation(gil);
    int fc = yc / 4 + pay;
    int sc = fc + (od == 1 ? 20 : 0);
    return thirdCalcuation(zl, sc);
}
