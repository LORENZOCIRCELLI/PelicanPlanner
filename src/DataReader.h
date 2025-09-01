// DataReader.h
#ifndef DATAREADER_H
#define DATAREADER_H

#include <vector>
#include <string>
#include "Crop.h"
#include "Gift.h"

class DataReader {
public:
    static void readCrops(const std::string& filename, std::vector<Crop>& crops);
    static void readGifts(const std::string& filename, std::vector<Gift>& gifts);
};

#endif
