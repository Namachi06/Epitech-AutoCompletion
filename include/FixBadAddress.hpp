/*
** EPITECH PROJECT, 2019
** FixBadAddress.hpp
** File description:
** Fix bad addresses in dictionary
*/

#ifndef FIXBADADDRESS_HPP_
#define FIXBADADDRESS_HPP_

#include <string>
#include <vector>
#include "Utils.hpp"
#include "Dictionary.hpp"

class FixBadAddress {
	public:
		FixBadAddress();
		~FixBadAddress();
		bool fixMissingComa(std::string &addr);
		bool fixMisplacedNumber(std::string &addr);
		bool fixMisplacedStreetType(std::string &addr);
		bool fixAddrBeforeCity(std::string &addr);
		bool fixBadAddr(std::string &dictioContent);

	private:
		Utils _utils;
		Dictionary _dictionary;
};

#endif /* !FIXBADADDRESS_HPP_ */
