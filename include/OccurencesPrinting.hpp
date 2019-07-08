/*
** EPITECH PROJECT, 2019
** OccurencesPrinting.hpp
** File description:
** Occurences printing format
*/

#ifndef OCCURENCESPRINTING_HPP_
#define OCCURENCESPRINTING_HPP_

#include "Dictionary.hpp"
#include "Occurences.hpp"
#include "Utils.hpp"
#include <vector>
#include <string>

class OccurencesPrinting {
	public:
		OccurencesPrinting();
		~OccurencesPrinting();
        void printMostOccurences(std::vector<std::string> dictioContent, int &occur_nbr, int &searchMode);
        void printMostOccurFormat(std::vector<std::pair<std::string, int>> occurLetters);
        void printFoundCityOccurences(std::vector<std::string> searchResult, int &occur_nbr, int &searchMode);
        void printFoundStreetOccurences(std::vector<std::string> searchResult, int &occur_nbr, int &searchMode);
        void printFoundOccurrences(std::vector<std::string> searchResult, int &occur_nbr, int &searchMode);
        void printFoundStreetOccurFormat(std::vector<std::string> searchResult,
            std::vector<std::pair<std::string, int>> occurLetters, int occur_nbr);
        void printFoundCityOccurFormat(std::vector<std::string> searchResult,
            std::vector<std::pair<std::string, int>> occurLetters, int occur_nbr);
        void printLastAddresses(std::vector<std::string> searchResult,
            std::vector<std::pair<std::string, int>> occurLetters, int occur_nbr);
        void sort(std::vector<std::pair<std::string, int>> &occurLetters);

    private:
        Dictionary _dictionary;
        Occurences _occurences;
        Utils _utils;
};

#endif /* !OCCURENCESPRINTING_HPP_ */
