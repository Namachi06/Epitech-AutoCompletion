/*
** EPITECH PROJECT, 2019
** Exceptions.hpp
** File description:
** Exceptions
*/

#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <exception>
#include <string>

namespace ACException
{
    class Exceptions : public std::exception {
        public:
            Exceptions(std::string const &e);
            ~Exceptions();
            virtual const char *what() const throw();

        private:
            std::string _errorMessage;
    };

    class ArgumentException : public Exceptions {
        public:
            ArgumentException(std::string const &errorMessage);
            ~ArgumentException();
    };

    class AddressException : public Exceptions {
        public:
            AddressException(std::string const &errorMessage);
            ~AddressException();
    };
};

#endif /* !EXCEPTIONS_HPP_ */
