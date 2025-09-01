// Gift.h
#ifndef GIFT_H
#define GIFT_H

#include <string>
#include <vector>
#include <iostream>

class Gift {
private:
    std::string character;
    std::vector<std::string> gifts;

public:
    Gift(const std::string& c);
    void addGift(const std::string& gift);
    void display() const;
    std::string getCharacter() const;
};

#endif
