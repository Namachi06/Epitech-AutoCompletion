/*
** EPITECH PROJECT, 2019
** OccurencesPrinting.cpp
** File description:
** Print occurences in specific format
*/

#include "../include/OccurencesPrinting.hpp"
#include <iostream>

OccurencesPrinting::OccurencesPrinting()
{
}

OccurencesPrinting::~OccurencesPrinting()
{
}

void OccurencesPrinting::printMostOccurFormat(std::vector<std::pair<std::string, int>> occurLetters)
{
    std::vector<std::pair<std::string, int>>::iterator occurLetter;
    int i = 0;

    for (occurLetter = occurLetters.begin(); i < 5 && occurLetter != occurLetters.end(); occurLetter++, i++) {
        std::cout << "{" << _utils.strToLowerUpper(occurLetter->first, 0) << "}";
        if (i < 4 && occurLetter + 1 != occurLetters.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void OccurencesPrinting::printMostOccurences(std::vector<std::string> dictioContent, int &occur_nbr, int &searchMode)
{
    std::vector<std::pair<std::string, int>> occurLetters;
    std::vector<std::pair<std::string, int>>::iterator occurLetter;
    std::vector<std::string>::iterator addr;
    std::vector<std::string> addr_split;
    int city_parts = 1;
    int i = 0;

    if (dictioContent.size() == 1) {
        std::cout << "=> " << dictioContent[0] << std::endl;
        return;
    }
    for (addr = dictioContent.begin(); addr != dictioContent.end(); addr++) {
        addr_split = _utils.split(*addr, " ");
        _dictionary.checkCity(addr_split, city_parts);
        for (; i < city_parts; i++) {
            if (_occurences.isOccurrenceExist(occurLetters, addr_split[i], 0))
                continue;
            _occurences.getCityOccurences(dictioContent, occurLetters,
                _utils.strToLowerUpper(addr_split[i], 0), 0);
        }
        i = 0;
        city_parts = 1;
    }
    sort(occurLetters);
    if (occurLetters.size() > 1)
        printMostOccurFormat(occurLetters);
    else {
        _occurences.searchCityOccurrences(occurLetters[0].first, dictioContent, occur_nbr);
        printFoundCityOccurences(dictioContent, occur_nbr, searchMode);
    }
}

void OccurencesPrinting::printFoundCityOccurences(std::vector<std::string> searchResult, int &occur_nbr, int &searchMode)
{
    std::vector<std::pair<std::string, int>> occurLetters;
    std::vector<std::pair<std::string, int>>::iterator occurLetter;
    std::vector<std::string>::iterator addr;
    std::vector<std::string> addr_split;
    int city_parts = 1;

    for (addr = searchResult.begin(); addr != searchResult.end(); addr++) {
        addr_split = _utils.split(*addr, " ");
        _dictionary.checkCity(addr_split, city_parts);
        if (_occurences.isOccurrenceExist(occurLetters, addr_split[0], occur_nbr))
            continue;
        _occurences.getCityOccurences(searchResult, occurLetters,
            _utils.strToLowerUpper(addr_split[0], 0), occur_nbr);
        city_parts = 1;
    }
    _utils.sortVectorOfPair(occurLetters, 2);
    _occurences.removeUselessOccurences(occurLetters);
    if (occurLetters.size() > 1)
        printFoundCityOccurFormat(searchResult, occurLetters, occur_nbr);
    else {
        occur_nbr = 0;
        searchMode = 1;
        printFoundStreetOccurences(searchResult, occur_nbr, searchMode);
    }
}

void OccurencesPrinting::printFoundStreetOccurences(std::vector<std::string> searchResult, int &occur_nbr, int &searchMode)
{
    std::vector<std::pair<std::string, int>> occurLetters;
    std::vector<std::pair<std::string, int>>::iterator occurLetter;
    std::vector<std::string>::iterator addr;
    std::vector<std::string> addr_split;
    int streetIdx = 0;
    int parts = 0;

    for (addr = searchResult.begin(); addr != searchResult.end(); addr++) {
        parts = 0;
        streetIdx = 0;
        addr_split = _utils.split(*addr, " ");
        _dictionary.getStreetNameIdx(addr_split, streetIdx, parts);
        for (int i = 0; i < parts; i++) {
            if (_occurences.isOccurrenceExist(occurLetters, addr_split[streetIdx + i], occur_nbr))
                continue;
            _occurences.getStreetOccurences(searchResult, occurLetters,
                _utils.strToLowerUpper(addr_split[streetIdx + i], 0), occur_nbr);
        }
    }
    sort(occurLetters);
    if (occurLetters.size() > 1)
        printFoundStreetOccurFormat(searchResult, occurLetters, occur_nbr);
    else {
        searchMode = 2;
        printLastAddresses(searchResult, occurLetters, occur_nbr);
    }
}

void OccurencesPrinting::printFoundOccurrences(std::vector<std::string> searchResult, int &occur_nbr, int &searchMode)
{
    if (searchResult.size() == 1) {
        std::cout << "=> " << searchResult[0] << std::endl;
        return;
    }
    if (searchMode == 0)
        printFoundCityOccurences(searchResult, occur_nbr, searchMode);
    else if (searchMode == 1)
        printFoundStreetOccurences(searchResult, occur_nbr, searchMode);
}

void OccurencesPrinting::printFoundStreetOccurFormat(std::vector<std::string> searchResult,
    std::vector<std::pair<std::string, int>> occurLetters, int occur_nbr)
{
    std::vector<std::pair<char, int>>::size_type j;

    for (j = 0; j < occurLetters.size(); j++) {
        std::cout<< "{";
        for (int i = 0; !_utils.strStr(searchResult[0].substr(0, i + 1), ","); i++)
            std::cout << std::toupper(searchResult[0][i], std::locale());
        std::cout << ", ";
        std::cout << occurLetters[j].first.substr(occur_nbr, 1);
        std::cout << "}";
        if (j + 1 != occurLetters.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void OccurencesPrinting::printFoundCityOccurFormat(std::vector<std::string> searchResult,
    std::vector<std::pair<std::string, int>> occurLetters, int occur_nbr)
{
    std::vector<std::pair<char, int>>::size_type j;

    for (j = 0; j < occurLetters.size(); j++) {
        std::cout<< "{";
        for (int i = 0; i < occur_nbr; i++) {
            if (searchResult[j][i])
                std::cout << std::toupper(searchResult[j][i], std::locale());
        }
        std::cout << occurLetters[j].first.substr(occur_nbr, 1);
        std::cout << "}";
        if (j + 1 != occurLetters.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void OccurencesPrinting::sort(std::vector<std::pair<std::string, int>> &occurLetters)
{
    std::vector<std::pair<std::string, int>> sortAlpha;
    std::vector<std::pair<std::string, int>>::iterator lst1 = occurLetters.begin();
    long unsigned int i = 0;
    long unsigned int j = 0;
    int idx = 0;

    _utils.sortVectorOfPair(occurLetters, 2);
    while (lst1 != occurLetters.end()) {
        for (; i < occurLetters.size(); i++) {
            if (occurLetters[i].second == lst1->second)
                sortAlpha.push_back(occurLetters[i]);
            else
                break;
        }
        _utils.sortVectorOfPair(sortAlpha, 1);
        for (; lst1 != occurLetters.end() && j < i; j++, lst1++)
            occurLetters[j] = sortAlpha[idx++];
        sortAlpha.clear();
        idx = 0;
    }
    _occurences.removeUselessOccurences(occurLetters);
}

void OccurencesPrinting::printLastAddresses(std::vector<std::string> searchResult,
    std::vector<std::pair<std::string, int>> occurLetters, int occur_nbr)
{
    std::vector<std::pair<char, int>>::size_type i;
    std::vector<std::pair<char, int>>::size_type j;
    std::vector<std::string> addr_split;

    for (j = 0; j < searchResult.size(); j++) {
        std::cout << "{";
        addr_split = _utils.split(searchResult[j], " ");
        std::cout << j + 1 << " : ";
        for (i = 0; i < addr_split.size(); i++) {
            if (_occurences.isOccurrenceExist(occurLetters, addr_split[i], occur_nbr) || i == 0)
                std::cout << _utils.strToLowerUpper(addr_split[i], 1);
            else
                std::cout << addr_split[i];
            if (i + 1 != addr_split.size())
                std::cout << " ";
        }
        std::cout << "}";
        if (j + 1 != searchResult.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}
