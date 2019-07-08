/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** Main program
*/

#include "../include/Exceptions.hpp"
#include "../include/AutoCompletion.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    (void)argc;
    try {
        AutoCompletion autoCompletion(argv);

        autoCompletion.run();
    } catch(ACException::Exceptions const &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}

