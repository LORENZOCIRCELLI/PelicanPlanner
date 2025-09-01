// Planner.cpp
#include "Planner.h"
#include "DataReader.h"
#include <iostream>
#include <string>

Planner::Planner(const std::vector<Crop>& c, const std::vector<Gift>& g)
    : crops(c), gifts(g) {}

void Planner::listAllCrops() const {
    for(const auto& crop : crops) crop.display();
}

void Planner::listAllGifts() const {
    for(const auto& gift : gifts) gift.display();
}

void Planner::searchGift() {
    std::string name;
    std::cout << "Enter character name: ";
    std::getline(std::cin, name);

    for(const auto& gift : gifts) {
        if(gift.getCharacter() == name) {
            gift.display();
            return;
        }
    }
    std::cout << "Character not found or cannot receive gifts!\n";
}

void Planner::cropFarmCalculator() const {
    std::string crop_name;
    int tiles, start_day;

    std::cout << "Enter crop name: ";
    std::getline(std::cin, crop_name);
    std::cout << "Enter number of tiles: ";
    std::cin >> tiles;
    std::cout << "Enter starting day: ";
    std::cin >> start_day;
    std::cin.ignore(); // limpar buffer

    for(const auto& crop : crops) {
        if(crop.getName() == crop_name) {
            crop.display();
            int regrow = crop.getRegrow();
            int grow = crop.getGrow();
            int remaining_days;
            int harvests;

            if(regrow == -1) {
                remaining_days = 28 - start_day;
                harvests = remaining_days / grow;
            } else {
                remaining_days = 28 - (start_day + grow);
                harvests = 1 + remaining_days / regrow;
            }

            std::cout << "Possible harvests: " << harvests << "\n";
            float profit = crop.getBaseValue() * harvests * tiles;
            if(profit >= 1000) std::cout << "Profit(minimal): $" << profit/1000 << "k\n";
            else std::cout << "Profit(minimal): $" << profit << "\n";
            return;
        }
    }
    std::cout << "Crop not found!\n";
}

void Planner::mainMenu() {
    int option = 0;
    while(option != 9) {
        std::cout << "\n1. Select character\n2. Show all characters\n3. Show all crops\n4. Crop Calculator\n9. Exit\nOption: ";
        std::cin >> option;
        std::cin.ignore(); // limpar buffer

        switch(option) {
            case 1: searchGift(); break;
            case 2: listAllGifts(); break;
            case 3: listAllCrops(); break;
            case 4: cropFarmCalculator(); break;
            case 9: break;
            default: std::cout << "Invalid option!\n";
        }
    }
}
