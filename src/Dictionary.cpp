/*
** EPITECH PROJECT, 2019
** Dictionary.cpp
** File description:
** Dictionary
*/

#include "../include/Dictionary.hpp"
#include "../include/Exceptions.hpp"
#include <fstream>
#include <sstream>

Dictionary::Dictionary()
{
    initStreetTypes();
}

Dictionary::~Dictionary()
{
}

void Dictionary::initStreetTypes()
{
    _streetType.push_back("allée");
    _streetType.push_back("avenue");
    _streetType.push_back("boulevard");
    _streetType.push_back("chemin");
    _streetType.push_back("impasse");
    _streetType.push_back("place");
    _streetType.push_back("quai");
    _streetType.push_back("rue");
    _streetType.push_back("square");
}

std::vector<std::string> Dictionary::getDictionary(const std::string fileName)
{
    std::ifstream file(fileName);
    std::vector<std::string> lines;
    std::string line;

    if (!file.is_open())
        throw ACException::ArgumentException("Can not open the file");
    while (getline(file, line))
        lines.push_back(line);
    if (lines.empty())
        throw ACException::ArgumentException("File empty");
    return (lines);
}

void Dictionary::getStreetNameIdx(std::vector<std::string> splitAddr, int &idx, int &parts)
{
    std::vector<std::string>::iterator elem = splitAddr.begin();

    for (; elem != splitAddr.end(); elem++) {
        if (!checkStreetType(*elem)) {
            idx++;
            continue;
        }
        idx++;
        break;
    }
    ++elem;
    for (; elem != splitAddr.end(); elem++)
        parts++;
}

bool Dictionary::checkCity(std::vector<std::string> splitAddr, int &nb_elem)
{
    std::vector<std::string>::iterator elem = splitAddr.begin();

    for (; elem != splitAddr.end(); elem++) {
        if (_utils.strStr(*elem, ",") == true)
            return (true);
        nb_elem++;
    }
    return (false);
}

bool Dictionary::checkStreetNumber(std::string streetNumber)
{
    if (!_utils.isDigit(streetNumber))
        return (false);
    return (true);
}

bool Dictionary::checkStreetType(std::string streetType)
{
    std::vector<std::string>::iterator type = _streetType.begin();

    for (; type != _streetType.end(); type++) {
        if (*type == streetType)
            return (true);
    }
    return (false);
}

bool Dictionary::checkBadAddress(std::string dictioContent)
{
    std::vector<std::string> splitAddr;
    int nb_elem = 0;

    splitAddr = _utils.split(dictioContent, " ");
    if (!checkCity(splitAddr, nb_elem))
        return (false);
    if (!checkStreetNumber(splitAddr[++nb_elem]))
        return (false);
    if (!checkStreetType(splitAddr[++nb_elem]))
        return (false);
    return (true);
}
