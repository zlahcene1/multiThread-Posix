/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Pizza
*/

#include "Pizza.hpp"

Pizza::Pizza()
{
    this->_type = NOTHING;
    this->_size = NOT;
}

Pizza::Pizza(const PizzaType &type, const PizzaSize &size)
{
    this->_type = type;
    this->_size = size;
}

Pizza::~Pizza()
{
}

PizzaType Pizza::getType(void)
{
    return _type;
}

PizzaSize Pizza::getSize(void)
{
    return _size;
}

std::string Pizza::pack(void)
{
    std::string str;

    for (auto &i : PizzaTypeString) {
        if (i.first == _type)
            str += i.second;
    }
    str += ",";
    for (auto &i : PizzaSizeString) {
        if (i.first == _size)
            str += i.second;
    }
    std::cout << str << std::endl;
    return str;
}

void Pizza::unpack(std::string str)
{
    std::string name;
    std::string size;
    std::stringstream ss(str);

    std::getline(ss, name, ',');
    std::getline(ss, size, ',');

    for (auto &i : PizzaSizeString) {
        if (i.second == size)
            _size = i.first;
    }
    for (auto &i : PizzaTypeString) {
        if (i.second == name)
            _type = i.first;
    }

    std::cout << _type << std::endl;
    std::cout << _size << std::endl;
}