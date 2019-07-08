/*
** EPITECH PROJECT, 2019
** Exceptions.cpp
** File description:
** Exceptions
*/

#include "../include/Exceptions.hpp"

ACException::Exceptions::Exceptions(std::string const &e) : _errorMessage(e)
{
}

ACException::Exceptions::~Exceptions()
{
}

const char *ACException::Exceptions::what() const throw()
{
    return _errorMessage.c_str();
}

ACException::ArgumentException::ArgumentException(std::string const &errorMessage) : Exceptions(errorMessage)
{
}

ACException::ArgumentException::~ArgumentException()
{
}

ACException::AddressException::AddressException(std::string const &errorMessage) : Exceptions(errorMessage)
{
}

ACException::AddressException::~AddressException()
{
}
