/*
** EPITECH PROJECT, 2022
** TODO_Plazza
** File description:
** header
*/

#ifndef HEADER_HPP_
    #define HEADER_HPP_

    #include <string>
    #include <map>
    #include <vector>
    #include <stack>

enum PizzaType
{
    NOTHING = 0,
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    NOT = 0,
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

enum Ingredient
{
    DOE,
    TOMATO,
    GRUYERE,
    HAM,
    MUSHROOMS,
    STEAK,
    GOAT_CHEESE,
    EGGPLANT,
    CHIEF_LOVE
};

typedef struct Recipe_s {
    PizzaType Type;
    Ingredient Elems[7];
    int TimeToCook;
} Recipe_t;


static const std::map<PizzaType, std::string> PizzaTypeString = {
    {Regina, "regina"},
    {Margarita, "margarita"},
    {Americana, "americana"},
    {Fantasia, "fantasia"}
};

static const std::map<std::string, PizzaType> PizzaTypeStringTwo = {
    {"regina", Regina},
    {"margarita", Margarita},
    {"americana", Americana},
    {"fantasia", Fantasia}
};

static const std::map<PizzaSize, std::string> PizzaSizeString = {
    {S, "S"},
    {M, "M"},
    {L, "L"},
    {XL, "XL"},
    {XXL, "XXL"}
};

static const std::map<std::string, PizzaSize> PizzaSizeStringTwo = {
    {"S", S},
    {"M", M},
    {"L", L},
    {"XL", XL},
    {"XXL", XXL}
};

static const std::vector<std::string> PizzaStringName = {
    "regina",
    "margarita",
    "americana",
    "fantasia"
};

static const std::vector<std::string> PizzaStringSize = {
    "S",
    "M",
    "L",
    "XL",
    "XXL"
};

static const Recipe_t PizzaRecipeList[] =
{
    {Margarita, {DOE, TOMATO, GRUYERE}, 1},
    {Regina,    {DOE, TOMATO, GRUYERE, HAM, MUSHROOMS}, 2},
    {Americana, {DOE, TOMATO, GRUYERE, STEAK}, 2},
    {Fantasia,  {DOE, TOMATO, EGGPLANT, GOAT_CHEESE, CHIEF_LOVE}, 4}
};

static const std::map<PizzaType, int> PizzaTimeToCook = {
    {Margarita, 1},
    {Regina, 2},
    {Americana, 2},
    {Fantasia, 4}
};

#endif /* !HEADER_HPP_ */