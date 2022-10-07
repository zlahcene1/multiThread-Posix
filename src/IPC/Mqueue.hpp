/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Mqueue
*/

#ifndef MQUEUE_HPP_
    #define MQUEUE_HPP_

    #include <mqueue.h>
    #include <string>
    #include "Pizza.hpp"

class Mqueue {
    public:
        Mqueue();
        ~Mqueue();

        void sendToKitchen(std::string name, Pizza pizza);
        void receiveFromKitchen(std::string name, Pizza pizza); 
        
        void sendToReception(std::string name, Pizza pizza);
        void receiveFromReception(std::string name, Pizza pizza);


    private:
        mqd_t _mq;
        struct mq_attr _attr;
};

#endif /* !MQUEUE_HPP_ */