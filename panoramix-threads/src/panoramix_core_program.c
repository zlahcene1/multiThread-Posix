/*
** EPITECH PROJECT, 2022
** PANORAMIX 2022
** File description:
** CORE PROGRAM
*/

#include "headers.h"

void *ft_druid(argument_t *s)
{
	printf("Druid: I'm ready... but sleepy...\n");
	while (s->druid_capacity > 0) {
		sem_wait(& s->dr);
		if (s->pot_usely <= 0) {
			pthread_mutex_lock(& s->locker);
			printf("Druid : Ah! Yes, yes, I'm awake! Working on it! Beware I can only make ");
			printf("%d more refills after this one.\n", s->druid_capacity);
			s->druid_capacity -= 1;
			s->pot_usely = s->pot_size;
			pthread_mutex_unlock(& s->locker);
			sem_post(&s->vi);
		}
	}
	printf("Druid: I’m out of viscum. I’m going back to... zZz\n");
}

int launch_program(argument_t *args)
{
    pthread_mutex_init(&args->locker, NULL);
    sem_init(&args->vi, 0, 1);
    sem_init(&args->dr, 0, 0);
    pthread_barrier_init(&args->barrier, NULL, args->nb_villagers);
	pthread_create(&args->thread_druid, NULL, (void *) ft_druid, args);
    for (int i = 0; i < args->nb_villagers; i++)
        pthread_create(&args->thread_villagers[i], NULL, (void *) ft_villager, args);
    pthread_join(args->thread_druid, NULL);
	for (int i = 0; i < args->nb_villagers; i++)
        pthread_join(args->thread_villagers[i], NULL);
	
	sem_destroy(& args->vi);
	sem_destroy(& args->dr);
	pthread_mutex_destroy(& args->locker);
	return 0;
}