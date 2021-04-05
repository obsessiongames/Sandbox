#include "FileReader.h"
#include <string>
#include <algorithm>

void readFile(std::string fileName, std::map<std::string, int>& parameterMap)
{
    std::ifstream inputFile;

    inputFile.open(fileName, std::ios::in);

    if (inputFile.fail())
    {
        throw std::runtime_error(fileName + " not successfully opened - does it exist?");
    }

    std::string line;
    while (getline(inputFile, line))
    {
        auto it = std::find(std::begin(line), std::end(line), '=');
        if (it == std::end(line))
            continue;
        std::string parameterName(std::begin(line), it);
        std::string valueAsString(++it, std::end(line));
        parameterMap[parameterName] = std::stoi(valueAsString);
    }

    inputFile.close();
}