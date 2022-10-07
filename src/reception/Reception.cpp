/*
** EPITECH PROJECT, 2022
** Reception
** File description:
** Reception
*/

#include "Reception.hpp"
#include "Kitchen.hpp"

Reception::Reception(int multiplier, int nb_cooks, int reloadTime)
{
    _multiplier = multiplier;
    _nb_cooks = nb_cooks;
    _reloadTime = reloadTime;
}

Reception::~Reception()
{
}

void Reception::core(void)
{
    addKitchen();

    while (true) {
        std::cout << "$> ";
        std::getline(std::cin, _cmd);
        if (_cmd.empty()) {
            std::cerr << "Error: Empty command" << std::endl;            
            continue;
        }
        parser(_cmd);
        if (_pids.empty()) {
            addKitchen();
            continue;
        }
            // IPC
    }
}

void Reception::addKitchen(void)
{
    pid_t pid = fork();

    if (pid == -1)
        throw std::runtime_error("fork error");
    else if (pid == 0) {
        Kitchen kitchen(_multiplier, _nb_cooks, _reloadTime);
        kitchen.core();
        exit(0);
    }
    else {
        _pids.push_back(pid);
    }
}

void Reception::parser(std::string Buf)
{
    std::vector<std::string> stackPizza;
    std::string delim = ";";    
    std::string Parsed;
    size_t pos = 0;
    std::string token;

    while ((pos = Buf.find(delim)) != std::string::npos) {
        token = Buf.substr(0, pos);
        stackPizza.push_back(token);
        Buf.erase(0, pos + delim.length());
    }
    stackPizza.push_back(Buf);
    for (auto &i : stackPizza) {
        std::stringstream ss(i);
        std::vector<std::string> tokens;
        std::string tmp;
        while (std::getline(ss, tmp, ' ')) {
            if (tmp != "")
                tokens.push_back(tmp);
        }
        if (tokens.size() != 3) {
            std::cerr << "Error: Wrong command" << std::endl;
            continue;
        }
        if (std::find(PizzaStringName.begin(), PizzaStringName.end(), tokens[0]) == PizzaStringName.end()) {
            std::cerr << "Error: Wrong command" << std::endl;
            continue;
        }
        if (std::find(PizzaStringSize.begin(), PizzaStringSize.end(), tokens[1]) == PizzaStringSize.end()) {
            std::cerr << "Error: Wrong command" << std::endl;
            continue;
        }
        if (tokens[2][0] != 'x' || !is_number(tokens[2].substr(1))) {
            std::cerr << "Error: Wrong command" << std::endl;
            continue;
        }
        for (int j = 0; j < std::stoi(tokens[2].substr(1)); j++) {
            _pizzas.push_back(Pizza(PizzaTypeStringTwo.at(tokens[0]), PizzaSizeStringTwo.at(tokens[1])));
        }
    }
    for (auto &i : _pizzas) {
        std::cout << PizzaTypeString.at (i.getType()) << " " << PizzaSizeString.at(i.getSize()) << std::endl;
    }
}