// Crop.h
#ifndef CROP_H
#define CROP_H

#include <string>
#include <iostream>

class Crop {
private:
    std::string name;
    int base_value;
    std::string season;
    std::string seller;
    int grow;
    int regrow;

    int silver_value;
    int golden_value;
    int iridium_value;

public:
    Crop(std::string n, int base, std::string s, std::string sel, int g, int r);
    void calculateValues();
    void display() const;

    std::string getName() const;
    int getGrow() const;
    int getRegrow() const;
    int getBaseValue() const;
    int getSilver() const;
    int getGolden() const;
    int getIridium() const;
};

#endif
