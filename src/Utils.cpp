/*
** EPITECH PROJECT, 2019
** Utils.cpp
** File description:
** Utils
*/

#include "../include/Utils.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

Utils::Utils()
{
}

Utils::~Utils()
{
}

bool Utils::isDigit(const std::string &s)
{
    std::string::const_iterator it = s.begin();

    for (; it != s.end() && std::isdigit(*it); it++);
    return !s.empty() && it == s.end();
}

void Utils::printUsage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./autoCompletion dictionary" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tdictionary file containing one address per line,"
        "as knowledge base" << std::endl;
}

std::vector<std::string> Utils::split(std::string str, std::string elem)
{
    std::vector<std::string> result;

    boost::split(result, str, boost::is_any_of(elem));
    return result;
}

std::vector<std::string> Utils::parseArgs(char **argv)
{
    std::vector<std::string> args;

    for (int i = 0; argv[i]; i++) {
        std::string arg(argv[i]);
        args.push_back(arg);
    }
    return (args);
}
bool Utils::strCaseCmp(const std::string &str1, const std::string &str2)
{
    if (boost::iequals(str1, str2))
        return (true);
    return (false);
}

bool Utils::strStr(const std::string &s, const std::string &str)
{
    if (s.empty() || str.empty())
        return (false);
    if (s.find(str) != std::string::npos)
        return (true);
    return (false);
}

unsigned long int Utils::strStrPos(const std::string &s, const std::string &str)
{
    if (s.find(str) != std::string::npos)
        return std::string::npos;
    return 0;
}

bool sortVectorBySec(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
    return (a.second > b.second);
}

void Utils::sortVectorOfPair(std::vector<std::pair<std::string, int>> &vector, int sortType)
{
    if (sortType == 1) {
        std::sort(vector.begin(), vector.end());
    } else if (sortType == 2) {
        std::sort(vector.begin(), vector.end(), sortVectorBySec);
    }
}

std::string Utils::concatVectorStr(std::vector<std::string> &vecStr)
{
    std::string str;

    for (const auto &vec : vecStr) {
        str += vec;
        str += " ";
    }
    str.pop_back();
    return (str);
}

char strToLower(char ch)
{
    if (ch <= 'Z' && ch >= 'A')
        return ch - ('Z' - 'z');
    return ch;
}

char strToUpper(char ch)
{
    if (ch <= 'z' && ch >= 'a')
        return ch - ('z' - 'Z');
    return ch;
}

int Utils::atoi(const std::string &s)
{
    int nbr;
    std::stringstream str(s);

    str >> nbr;
    return (nbr);
}

std::string Utils::strToLowerUpper(const std::string str, int mode)
{
    std::string result(str);

    if (mode == 0)
        std::transform(result.begin(), result.end(), result.begin(), strToLower);
    if (mode == 1)
        std::transform(result.begin(), result.end(), result.begin(), strToUpper);
    return (result);
}
