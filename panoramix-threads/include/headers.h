/*
** EPITECH PROJECT, 2022
** PANAROMIX
** File description:
** HEADERS ECT
*/

#ifndef HEADERS_H_
#define HEADERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>

typedef struct
{
    int nb_fights;
    int nb_villagers;
    int pot_size;
    int druid_capacity;
    int tmp;
    int pot_usely;

    pthread_mutex_t locker;
    pthread_barrier_t barrier;
    sem_t vi;
    sem_t dr;
    pthread_t *thread_villagers;
    pthread_t thread_druid;

} argument_t;


// ----------ARGUMENTS FUBNCTIONS ----------------//

bool great_number(char **argument, int size);
int launch_program(argument_t *args);
void *ft_villager(argument_t *s);

#endif