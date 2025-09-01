// Planner.h
#ifndef PLANNER_H
#define PLANNER_H

#include <vector>
#include "Crop.h"
#include "Gift.h"

class Planner {
private:
    std::vector<Crop> crops;
    std::vector<Gift> gifts;

    void searchGift();
    void listAllCrops() const;
    void listAllGifts() const;
    void cropFarmCalculator() const;

public:
    Planner(const std::vector<Crop>& c, const std::vector<Gift>& g);
    void mainMenu();
};

#endif
