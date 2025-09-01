#include "DataReader.h"
#include "Planner.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Crop> crops;
    std::vector<Gift> gifts;

    DataReader::readCrops("data/crops.csv", crops);
    DataReader::readGifts("data/gifts.csv", gifts);

    Planner planner(crops, gifts);
    planner.mainMenu();

    return 0;
}
