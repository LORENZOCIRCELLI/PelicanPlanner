// DataReader.cpp
#include "DataReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

void DataReader::readCrops(const std::string& filename, std::vector<Crop>& crops) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cout << "Cannot open crops file!\n";
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, season, seller, token;
        int base_value, grow, regrow = -1;

        std::getline(ss, name, ',');
        std::getline(ss, token, ','); base_value = std::stoi(token);
        std::getline(ss, season, ',');
        std::getline(ss, seller, ',');
        std::getline(ss, token, ','); grow = std::stoi(token);
        if(std::getline(ss, token, ',')) regrow = std::stoi(token);

        crops.push_back(Crop(name, base_value, season, seller, grow, regrow));
    }
}

void DataReader::readGifts(const std::string& filename, std::vector<Gift>& gifts) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cout << "Cannot open gifts file!\n";
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::string character;
        std::getline(ss, character, ',');

        Gift g(character);
        std::string gift;
        while(std::getline(ss, gift, ',')) g.addGift(gift);

        gifts.push_back(g);
    }
}
