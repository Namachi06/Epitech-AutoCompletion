/*
** EPITECH PROJECT, 2019
** Occurences.hpp
** File description:
** Occurences
*/

#ifndef OCCURENCES_HPP_
#define OCCURENCES_HPP_

#include <string>
#include <vector>
#include "Utils.hpp"
#include "Dictionary.hpp"

class Occurences {
	public:
		Occurences();
		~Occurences();
        void searchCityOccurrences(std::string input, std::vector<std::string> &dictioContent, int &occur_nbr);
        void searchStreetOccurrences(std::string input, std::vector<std::string> &dictioContent, int &occur_nbr);
        void searchStoreOccurences(std::string input, std::vector<std::string> &dictioContent, int &occur_nbr, int searchMode);
        void searchLastAddress(std::string input, std::vector<std::string> &dictioContent);
        bool isOccurrenceExist(std::vector<std::pair<std::string, int>> &occurLetters, std::string &addr, int idx);
        void getStreetOccurences(std::vector<std::string> dictioContent,
            std::vector<std::pair<std::string, int>> &occurLetters, std::string firstLetter, int idx);
        void getCityOccurences(std::vector<std::string> dictioContent,
            std::vector<std::pair<std::string, int>> &occurLetters, std::string firstLetter, int idx);
        void removeUselessOccurences(std::vector<std::pair<std::string, int>> &occurLetters);

    private:
        Utils _utils;
        Dictionary _dictionary;
};

#endif /* !OCCURENCES_HPP_ */
