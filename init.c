/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:36:09 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/16 10:38:39 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// initialisation des philosophers
int init_philo(t_args *args)
{
    int i;

    i = args->nb_of_philo;
    while (i >= 0)
    {
        args->philo[i].id = i;
        args->philo[i].amount_ate = 0;
        args->philo[i].l_fork = i;
        args->philo[i].r_fork = (i + 1) % args->nb_of_philo;
        args->philo[i].last_meal = 0;
        i--;
    }
}

// initialisation de la strucutre principale au lancement du programme
int init_struct(t_args *philo, char **av, int ac)
{
    philo->amount_to_eat = -1;
    philo->nb_of_philo = ft_atoi(av[1]);
    philo->t_die = ft_atoi(av[2]);
    philo->t_eat = ft_atoi(av[3]);
    philo->t_sleep = ft_atoi(av[4]);
    if (ac == 6)
        philo->amount_to_eat = ft_atoi(av[5]);
}