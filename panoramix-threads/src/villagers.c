/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** villagers
*/

#include "headers.h"

void condition_no_pano(argument_t *s)
{
	if (s->pot_usely == 0 && s->druid_capacity == 0) {
		pthread_mutex_unlock(&s->locker);
		sem_post(& s->vi);
	}
}

void condition_no_pot(argument_t *s, int id)
{
	if (s->pot_usely == 0) {
		printf ("Villager %d: Hey Pano wake up! We need more potion.\n", id);
		pthread_mutex_unlock(&s->locker);
		sem_post(& s->dr);
		sem_wait(& s->vi);
	}
}

int normal_case(argument_t *s, int id, int n_f)
{
	n_f -= 1;
	s->pot_usely -= 1;
	printf("Villager %d: Take that roman scum! Only ", id);
	printf("%d left.\n", (n_f <= 0 ? 0 : n_f));
	return n_f;
}

void *ft_villager(argument_t *s)
{
	int id = s->tmp++;
	int n_f = s->nb_fights;

	printf("Villager %d: Going into battle!\n", id);
	pthread_barrier_wait(&s->barrier);
	while (n_f > 0) {
		sem_wait(& s->vi);
		pthread_mutex_lock(&s->locker);
		printf("Villager %d: I need a drink... I see %d servings left.\n", id, s->pot_usely);
		condition_no_pano(s);
		condition_no_pot(s, id);
		n_f = normal_case(s, id, n_f);
		pthread_mutex_unlock(&s->locker);
		sem_post(&s->vi);
	}
	printf("Villager %d: I'm going to sleep now.\n", id);
}
