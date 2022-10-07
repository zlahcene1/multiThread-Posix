/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(int multiplier, int nb_cooks, int reloadTime)
{
    std::cout << "Kitchen created" << std::endl;
    _reloadTime = reloadTime;
    _nb_cooks = 0;
    for (int i = 0; i < nb_cooks; i++) {
       _cooks.push_back(std::thread(Kitchen::cooks, std::ref(_mutex), std::ref(_pizzas), std::ref(_cond), multiplier, _close, std::ref(_nb_cooks), std::ref(_close_kitchen)));
    }
}

Kitchen::~Kitchen()
{
}

void Kitchen::core()
{
    auto clock = std::chrono::system_clock::now();
    _close_kitchen = std::chrono::system_clock::now();

    {
        std::unique_lock<std::mutex> lock(_mutex);
        _pizzas.push_back(Pizza(Margarita, S));
    }
    _cond.notify_one();
    while (true) {
        if (std::chrono::system_clock::now() - clock > std::chrono::seconds(_reloadTime)) {
            fillFridge();
            clock = std::chrono::system_clock::now();
        }
        std::unique_lock<std::mutex> lock(_mutex);
        if (std::chrono::system_clock::now() - _close_kitchen > std::chrono::seconds(5) && _nb_cooks == 0) {            
            std::cout << "Kitchen closed" << std::endl;
            break;
        }
    }
    closeKitchen();
}

void Kitchen::closeKitchen()
{
    _close = true;
    _cond.notify_all();
    for (auto &cook : _cooks)
        cook.join();
    std::cout << "Function Kitchen closed" << std::endl;
}

void Kitchen::cooks(std::mutex &mutex, std::vector<Pizza> &pizzas, std::condition_variable &cond, int multiplier, int close, int &closeKitchen, std::chrono::system_clock::time_point &clock)
{
    std::cout << "cuisinier start " << std::endl;
    while (1) {
        Pizza pizza;
        {
            std::unique_lock<std::mutex> lock(mutex);
            cond.wait(lock, [&] {return !pizzas.empty() || close;});
            if (close == true)
                break;
            pizza = pizzas.back();
            pizzas.pop_back();
            closeKitchen += 1;
        }
        sleep(multiplier * PizzaTimeToCook.at(pizza.getType()));
        std::cout << "pizza cooked " << PizzaTypeString.at(pizza.getType()) << std::endl;
        {
            std::unique_lock<std::mutex> lock(mutex);
            closeKitchen -= 1;
            clock = std::chrono::system_clock::now();
        }
    }
    std::cout << "cuisinier end" << std::endl;
}

void Kitchen::fillFridge()
{
    for (auto &i : IngredientList) {
        if (i.second < 5) {
            i.second += 1;
        }
    }
}