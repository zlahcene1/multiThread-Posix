/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Main
*/

#include "Reception.hpp"
#include "Pizza.hpp"
#include "Kitchen.hpp"
#include "Mqueue.hpp"

int main(int ac, char **av)
{
    Reception R(2, 5, 2000);

    R.core();   
    // Kitchen K(2, 5, 2000);
    
    // K.core();

    return 0;
}