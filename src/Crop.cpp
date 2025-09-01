// Crop.cpp
#include "Crop.h"

Crop::Crop(std::string n, int base, std::string s, std::string sel, int g, int r)
    : name(n), base_value(base), season(s), seller(sel), grow(g), regrow(r) {
    calculateValues();
}

void Crop::calculateValues() {
    silver_value = static_cast<int>(base_value * 1.25);
    golden_value = static_cast<int>(base_value * 1.5);
    iridium_value = base_value * 2;
}

void Crop::display() const {
    std::cout << "Name: " << name << "\n"
              << "Base Value: $" << base_value << "\n"
              << "Season: " << season << "\n"
              << "Vendor: " << seller << "\n"
              << "Silver: $" << silver_value << ", Gold: $" << golden_value << ", Iridium: $" << iridium_value << "\n";
}

std::string Crop::getName() const { return name; }
int Crop::getGrow() const { return grow; }
int Crop::getRegrow() const { return regrow; }
int Crop::getBaseValue() const { return base_value; }
int Crop::getSilver() const { return silver_value; }
int Crop::getGolden() const { return golden_value; }
int Crop::getIridium() const { return iridium_value; }
