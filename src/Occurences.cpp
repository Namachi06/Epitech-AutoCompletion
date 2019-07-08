/*
** EPITECH PROJECT, 2019
** Occurences.cpp
** File description:
** Occurences
*/

#include "../include/Occurences.hpp"
#include "../include/Exceptions.hpp"
#include <iostream>

Occurences::Occurences()
{
}

Occurences::~Occurences()
{
}

void Occurences::searchCityOccurrences(std::string input, std::vector<std::string> &dictioContent, int &occur_nbr)
{
    std::vector<std::string>::iterator addr;
    std::vector<std::string> addr_split;
    int city_parts = 1;
    int i = 0;
    bool exist = false;

    for (addr = dictioContent.begin(); addr != dictioContent.end(); addr++) {
        addr_split = _utils.split(*addr, " ");
        _dictionary.checkCity(addr_split, city_parts);
        for (; i < city_parts; i++) {
            if (std::tolower(addr_split[i][occur_nbr], std::locale()) == std::tolower(input[0], std::locale())) {
                exist = true;
                break;
            }
            exist = false;
        }
        if (!exist)
            dictioContent.erase(addr--);
        i = 0;
        city_parts = 1;
    }
    occur_nbr++;
}

void Occurences::searchStreetOccurrences(std::string input, std::vector<std::string> &dictioContent, int &occur_nbr)
{
    std::vector<std::string>::iterator addr;
    std::vector<std::string> addr_split;
    int streetIdx = 0;
    int parts = 0;
    int i = 0;
    bool exist = false;

    for (addr = dictioContent.begin(); addr != dictioContent.end(); addr++) {
         addr_split = _utils.split(*addr, " ");
        _dictionary.getStreetNameIdx(addr_split, streetIdx, parts);
        for (; i < parts; i++) {
            if (std::tolower(addr_split[streetIdx + i][occur_nbr], std::locale()) == std::tolower(input[0], std::locale())) {
                exist = true;
                break;
            }
            exist = false;
        }
        if (!exist)
            dictioContent.erase(addr--);
        streetIdx = 0;
        i = 0;
        parts = 0;
    }
    occur_nbr++;
}

void Occurences::searchStoreOccurences(std::string input, std::vector<std::string> &dictioContent, int &occur_nbr, int searchMode)
{
    if (searchMode == 0)
        searchCityOccurrences(input, dictioContent, occur_nbr);
    else if (searchMode == 1)
        searchStreetOccurrences(input, dictioContent, occur_nbr);
    else
        searchLastAddress(input, dictioContent);

    if (dictioContent.empty())
        throw ACException::AddressException("Unknown address");
}

void Occurences::searchLastAddress(std::string input, std::vector<std::string> &dictioContent)
{
    int inputNbr = 0;
    std::vector<std::string>::iterator addr;

    if (!_utils.isDigit(input))
        throw ACException::ArgumentException("Invalid argument");
    inputNbr = _utils.atoi(input);
    for (addr = dictioContent.begin(); addr != dictioContent.end(); addr++) {
        if (*addr != dictioContent[--inputNbr])
            dictioContent.erase(addr--);
    }
}

bool Occurences::isOccurrenceExist(std::vector<std::pair<std::string, int>> &occurLetters, std::string &addr, int idx)
{
    std::vector<std::pair<std::string, int>>::iterator occurLetter = occurLetters.begin();

    for (; occurLetter != occurLetters.end(); occurLetter++) {
        if (_utils.strToLowerUpper(occurLetter->first, 0) == _utils.strToLowerUpper(addr.substr(0, idx + 1), 0)) {
            return (true);
        }
    }
    return (false);
}

void Occurences::getStreetOccurences(std::vector<std::string> dictioContent,
    std::vector<std::pair<std::string, int>> &occurLetters, std::string firstLetter, int idx)
{
    std::vector<std::string>::iterator addr;
    std::vector<std::string> addr_split;
    int count = 0;
    int streetIdx = 0;
    int parts = 0;

    for (addr = dictioContent.begin(); addr != dictioContent.end(); addr++) {
        streetIdx = 0;
        parts = 0;
        addr_split = _utils.split(*addr, " ");
        _dictionary.getStreetNameIdx(addr_split, streetIdx, parts);
        for (int i = 0; i < parts; i++) {
            if (_utils.strToLowerUpper(addr_split[streetIdx + i].substr(0, idx + 1), 0) == firstLetter.substr(0, idx + 1))
                count++;
        }
    }
    if (count != 0)
        occurLetters.push_back(std::make_pair(_utils.strToLowerUpper(firstLetter.substr(0, idx + 1), 0), count));
}

void Occurences::getCityOccurences(std::vector<std::string> dictioContent,
    std::vector<std::pair<std::string, int>> &occurLetters, std::string firstLetter, int idx)
{
    std::vector<std::string>::iterator addr;
    std::vector<std::string> addr_split;
    int count = 0;
    int city_part = 1;
    int i = 0;

    for (addr = dictioContent.begin(); addr != dictioContent.end(); addr++) {
        addr_split = _utils.split(*addr, " ");
        _dictionary.checkCity(addr_split, city_part);
        for (; i < city_part; i++) {
            if (_utils.strToLowerUpper(addr_split[i].substr(0, idx + 1), 0) == firstLetter.substr(0, idx + 1))
                count++;
        }
        i = 0;
        city_part = 1;
    }
    if (count != 0)
        occurLetters.push_back(std::make_pair(_utils.strToLowerUpper(firstLetter.substr(0, idx + 1), 0), count));
}

void Occurences::removeUselessOccurences(std::vector<std::pair<std::string, int>> &occurLetters)
{
    std::vector<std::pair<std::string, int>>::iterator occurLetter = occurLetters.begin();
    std::vector<std::pair<std::string, int>> letterToSort;
    std::vector<std::pair<std::string, int>>::size_type i;

    if (occurLetters.size() <= 5)
        return;
    for (i = 4; i < occurLetters.size(); i++) {
        for (; occurLetter != occurLetters.end(); occurLetter++) {
            if (occurLetters[i].second == occurLetter->second)
                letterToSort.push_back(*occurLetter);
        }
    }
    std::sort(letterToSort.begin(), letterToSort.end());
    letterToSort.pop_back();
    occurLetters.pop_back();
    occurLetters.pop_back();
    occurLetters.push_back(letterToSort[0]);
}
