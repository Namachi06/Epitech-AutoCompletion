/*
** EPITECH PROJECT, 2019
** Dictionary.hpp
** File description:
** Dictionary
*/

#ifndef DICTIONARY_HPP_
#define DICTIONARY_HPP_

#include <string>
#include <vector>
#include "../include/Utils.hpp"

class Dictionary {
	public:
		Dictionary();
		~Dictionary();
        void initStreetTypes();
        std::vector<std::string> getDictionary(std::string file);
        bool checkCity(std::vector<std::string> splitAddr, int &nb_elem);
        void getStreetNameIdx(std::vector<std::string> splitAddr, int &idx, int &parts);
        bool checkStreetNumber(std::string dictioContent);
        bool checkStreetType(std::string streetType);
        bool checkBadAddress(std::string dictioContent);

	private:
        Utils _utils;
        std::vector<std::string> _streetType;

};

#endif /* !DICTIONARY_HPP_ */
