// Gift.cpp
#include "Gift.h"

Gift::Gift(const std::string& c) : character(c) {}

void Gift::addGift(const std::string& gift) {
    if(!gift.empty()) gifts.push_back(gift);
}

void Gift::display() const {
    std::cout << "Character: " << character << "\n";
    if(gifts.empty()) {
        std::cout << "This character can't receive gifts!\n";
    } else {
        for(size_t i = 0; i < gifts.size(); ++i)
            std::cout << "Gift " << i+1 << ": " << gifts[i] << "\n";
    }
    std::cout << "----------------------------------\n";
}

std::string Gift::getCharacter() const { return character; }
