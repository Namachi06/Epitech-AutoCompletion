/*
** EPITECH PROJECT, 2019
** FixBadAddress.cpp
** File description:
** Fix te bad addresses in dictionary
*/

#include "../include/FixBadAddress.hpp"

FixBadAddress::FixBadAddress()
{
}

FixBadAddress::~FixBadAddress()
{
}

bool FixBadAddress::fixMissingComa(std::string &addr)
{
    std::vector<std::string> addr_split;
    std::vector<std::string>::iterator it;

    if (_utils.strStr(addr, ","))
        return (false);
    addr_split = _utils.split(addr, " ");
    for (it = addr_split.begin(); it != addr_split.end(); it++) {
        if (!_utils.isDigit(*it))
            continue;
        addr_split[--it - addr_split.begin()].push_back(',');
        addr = _utils.concatVectorStr(addr_split);
        return (true);
    }
    return (false);
}

bool FixBadAddress::fixMisplacedNumber(std::string &addr)
{
    std::vector<std::string> addr_split = _utils.split(addr, " ");
    std::vector<std::string>::iterator it;
    std::string number;

    for (it = addr_split.begin(); it != addr_split.end(); it++) {
        if (!_utils.isDigit(*it))
            continue;
        if (it == addr_split.begin() + 1)
            return (false);
        number = *it;
        addr_split.erase(it--);
        it = addr_split.begin() + 1;
        addr_split.insert(it, number);
        addr = _utils.concatVectorStr(addr_split);
        return (true);
    }
    return (false);
}

bool FixBadAddress::fixMisplacedStreetType(std::string &addr)
{
    std::vector<std::string> addr_split = _utils.split(addr, " ");
    std::vector<std::string>::iterator it;
    std::string street;
    bool number = false;

    for (it = addr_split.begin(); it != addr_split.end(); it++) {
        if (_dictionary.checkStreetNumber(*it))
            number = true;
        if (!_dictionary.checkStreetType(*it))
            continue;
        if (it == (addr_split.begin() + 2) || !number)
            return (false);
        street = *it;
        addr_split.erase(it--);
        it = addr_split.begin() + 2;
        addr_split.insert(it, street);
        addr = _utils.concatVectorStr(addr_split);
        return (true);
    }
    return (false);
}

bool FixBadAddress::fixAddrBeforeCity(std::string &addr)
{
    std::vector<std::string> addr_split = _utils.split(addr, " ");
    std::vector<std::string>::iterator it;
    std::string city;

    for (it = addr_split.begin(); it != addr_split.end(); it++) {
        if (!_utils.strStr(*it, ","))
            continue;
        if (it == addr_split.begin())
            return (false);
        addr_split[it++ - addr_split.begin()].pop_back();
        city = *it;
        addr_split.erase(it--);
        it = addr_split.begin();
        city.push_back(',');
        addr_split.insert(it, city);
        addr = _utils.concatVectorStr(addr_split);
        return (true);
    }
    return (false);
}

bool FixBadAddress::fixBadAddr(std::string &addr)
{
    bool fixDone = false;

    if (fixMissingComa(addr))
        fixDone = true;
    if (fixAddrBeforeCity(addr))
        fixDone = true;
    if (fixMisplacedNumber(addr))
        fixDone = true;
    if (fixMisplacedStreetType(addr))
        fixDone = true;
    return (fixDone);
}
