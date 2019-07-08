/*
** EPITECH PROJECT, 2019
** Utils.hpp
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

class Utils {
	public:
		Utils();
		~Utils();
        void printUsage();
        bool isDigit(const std::string &s);
        bool strCaseCmp(const std::string &str1, const std::string &str2);
        bool strStr(const std::string &s, const std::string &str);
        unsigned long int strStrPos(const std::string &s, const std::string &str);
        std::vector<std::string> parseArgs(char **argv);
        std::vector<std::string> split(std::string str, std::string elem);
        void sortVectorOfPair(std::vector<std::pair<std::string, int>> &vector, int sortType);
        std::string concatVectorStr(std::vector<std::string> &vecStr);
        int atoi(const std::string &s);
        std::string strToLowerUpper(const std::string str, int mode);
};

#endif /* !UTILS_HPP_ */
