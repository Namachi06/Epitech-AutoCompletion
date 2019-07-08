/*
** EPITECH PROJECT, 2019
** AutoCompletion.cpp
** File description:
** Auto Completion
*/

#include "../include/AutoCompletion.hpp"
#include "../include/Exceptions.hpp"
#include <iostream>
#include <sstream>
#include <csignal>

State _state = RUN;

void signalHandler(int sigNum)
{
    _state = EXIT;
    (void)sigNum;
}

AutoCompletion::AutoCompletion(char **argv)
{
    _args =  _utils.parseArgs(argv);
    if (_args.size() != 2)
        throw ACException::ArgumentException("Invalid argument");
    if (_args[1] == "-h") {
        _utils.printUsage();
        return;
    }
    _dictioContent =  _dictionary.getDictionary(_args[1]);
}

AutoCompletion::~AutoCompletion()
{
}

void AutoCompletion::handleBadAddresses()
{
    std::vector<std::string>::iterator addr = _dictioContent.begin();
    for (; addr != _dictioContent.end(); addr++) {
        if (!_dictionary.checkBadAddress(*addr)) {
            if (!_fixAddr.fixBadAddr(*addr)) {
                std::cerr << *addr << std::endl;
                _dictioContent.erase(addr--);
            }
        }
    }
}

void AutoCompletion::run()
{
    std::string input;
    int occur_nbr = 0;
    int searchMode = 0;

    signal(SIGINT, signalHandler);
    handleBadAddresses();
    _printOccurs.printMostOccurences(_dictioContent, occur_nbr, searchMode);
    while (_state == RUN && _dictioContent.size() != 1 && getline(std::cin, input)) {
        if (_utils.strCaseCmp(input, "abort"))
            return;
        if (input.size() > 1)
            throw ACException::ArgumentException("Invalid argument");
        _occurences.searchStoreOccurences(input, _dictioContent, occur_nbr, searchMode);
        _printOccurs.printFoundOccurrences(_dictioContent, occur_nbr, searchMode);
    }
}
