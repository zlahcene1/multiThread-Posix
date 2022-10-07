/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Usage
*/

#include "Reception.hpp"

bool Reception::is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void Reception::exitProgram(void)
{
    std::cout << "./plazza N1 N2 N3" <<std::endl;
    std::cout << "\tN1:\tcooking time for a Pizza." <<std::endl;
    std::cout << "\tN2:\tnb cooks per kitchen." <<std::endl;
    std::cout << "\tN3:\tnb milliseconds for refills ingredients."<<std::endl;
    std::exit(84);
}

void Reception::usage(void)
{
    std::cout << "All of your order MUST follow this gammar:"<< std::endl;
    std::cout << "\tS := TYPE SIZE NUMBER [; TYPE SIZE NUMBER ]*"<< std::endl;
    std::cout<< "\tTYPE := [ a .. zA .. Z ]+" << std::endl;
    std::cout<< "\tSIZE := S | M | L | XL | XXL" << std::endl;
    std::cout<< "\tNUMBER := x [1..9][0..9]*" << std::endl;
}

void Reception::checkArgument(int ac, char **av)
{
    if (ac != 4)
        exitProgram();
    for (int i = 1; i < ac; i++)
        for (int j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] < '0' || av[i][j] > '9')
                exitProgram();
}