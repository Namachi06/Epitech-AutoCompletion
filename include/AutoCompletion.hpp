/*
** EPITECH PROJECT, 2019
** AutoCompletion.hpp
** File description:
** Auto Completion
*/

#ifndef AUTOCOMPLETION_HPP_
#define AUTOCOMPLETION_HPP_

#include "Utils.hpp"
#include "Dictionary.hpp"
#include "Occurences.hpp"
#include "OccurencesPrinting.hpp"
#include "FixBadAddress.hpp"
#include <vector>
#include <string>
#include <map>

enum State
{
    RUN,
    EXIT
};

class AutoCompletion {
	public:
		AutoCompletion(char **argv);
        void handleBadAddresses();
        void run();
		~AutoCompletion();

	private:
        Utils _utils;
        Dictionary _dictionary;
        Occurences _occurences;
        OccurencesPrinting _printOccurs;
        FixBadAddress _fixAddr;
        std::vector<std::string> _dictioContent;
        std::vector<std::string> _args;
};

#endif /* !AUTOCOMPLETION_HPP_ */
