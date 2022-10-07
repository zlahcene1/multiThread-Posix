/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
    #define PIZZA_HPP_

    #include <iostream>
    #include <stack>
    #include <vector>
    #include <unistd.h>
    #include <wait.h>
    #include <sstream> 
    #include <string>
    #include "Utils.hpp"

class Pizza {
    public:
        Pizza();
        Pizza(const PizzaType &type, const PizzaSize &size);
        ~Pizza();

        PizzaType getType(void);
        PizzaSize getSize(void);

        std::string pack(void);
        void unpack(std::string str);

    private:
        PizzaType _type;
        PizzaSize _size;
};



#endif /* !PIZZA_HPP_ */