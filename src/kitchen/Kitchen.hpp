/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

    #include <thread>
    #include <mutex>
    #include <condition_variable>
    #include <stdbool.h>
    #include "Utils.hpp"
    #include "Reception.hpp"
    #include "Pizza.hpp"

class Kitchen {
    
    public:
        Kitchen(int multiplier, int nb_cooks, int _rechargeTime);
        ~Kitchen();

        void core();
        void fillFridge();
        static void cooks(std::mutex &mutex, std::vector<Pizza> &pizzas, std::condition_variable &cond, int multiplier, int close, int &closeKitchen, std::chrono::system_clock::time_point &clock);

        void closeKitchen();


    private:
        int _reloadTime;
        std::vector<std::string> _fridge;
        std::vector<std::thread> _cooks;
        std::vector<Pizza> _pizzas;
        std::mutex _mutex;
        std::condition_variable _cond;
        bool _close = false;
        int _nb_cooks;
        std::chrono::system_clock::time_point _close_kitchen;

    std::map<Ingredient, int> IngredientList = {
        {DOE, 5},
        {TOMATO, 5},
        {GRUYERE, 5},
        {HAM, 5},
        {MUSHROOMS, 5},
        {STEAK, 5},
        {GOAT_CHEESE, 5},
        {EGGPLANT, 5},
        {CHIEF_LOVE, 5}
    };
};

#endif /* !KITCHEN_HPP_ */