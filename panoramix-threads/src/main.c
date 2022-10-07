#include "headers.h"

bool catch_argument(int ac, char **av)
{
    if (ac != 5)
        return false;
    else if (!great_number(av, ac))
        return false;
    else
        return true;
}

int main(int ac, char **av)
{
    argument_t args;

	if (!catch_argument(ac, av))
        return 84;
    args.nb_villagers = atoi(av[1]);
    args.pot_size = atoi(av[2]);
    args.pot_usely = atoi(av[2]);
    args.nb_fights = atoi(av[3]);
    args.druid_capacity = atoi(av[4]);
    args.thread_villagers = malloc(sizeof(pthread_t) * atoi(av[1]));
    args.tmp = 0;
    return launch_program(& args);
}