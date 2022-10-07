/*
** EPITECH PROJECT, 2022
** Reception
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_

    #include <iostream>
    #include <sstream>
    #include <algorithm>
    #include "Utils.hpp"
    #include "Pizza.hpp"

class Reception {
    public:
        Reception(int multiplier, int nb_cooks, int reloadTime);
        ~Reception();

        void core(void);
        void exitProgram(void);
        void usage(void);
        void checkArgument(int, char **);
        void parseInput(const std::string &);
        void parser(const std::string);
        bool is_number(const std::string &);
        
        void addKitchen(void);


    private:
        int _multiplier;
        int _nb_cooks;
        int _reloadTime;
        std::vector<Pizza> _pizzas;
        std::vector<pid_t> _pids;
        std::string _cmd;
};

#endif /* !Reception_HPP_ */
