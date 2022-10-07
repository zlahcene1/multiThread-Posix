/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Mqueue
*/

#include "Mqueue.hpp"
#include "Pizza.hpp"

Mqueue::Mqueue()
{
    _mq = mq_open("/plazza", O_RDWR | O_CREAT, 0666, NULL);
    _attr.mq_maxmsg = 1000;
    _attr.mq_msgsize = sizeof(Pizza);
    _attr.mq_flags = 0;
    mq_setattr(_mq, &_attr, NULL);
}

Mqueue::~Mqueue()
{
}

void Mqueue::sendToKitchen(std::string name, Pizza pizza)
{
    mq_send(_mq, (char *)&pizza, sizeof(Pizza), 0);
}

void Mqueue::sendToReception(std::string name, Pizza pizza)
{
    mq_send(_mq, (char *)&pizza, sizeof(Pizza), 0);
}

void Mqueue::receiveFromKitchen(std::string name, Pizza pizza)
{
    mq_receive(_mq, (char *)&pizza, sizeof(Pizza), 0);
}

void Mqueue::receiveFromReception(std::string name, Pizza pizza)
{
    mq_receive(_mq, (char *)&pizza, sizeof(Pizza), 0);
}
