/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tanguy <Tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:03:37 by Tanguy            #+#    #+#             */
/*   Updated: 2021/12/09 09:21:56 by Tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* initialisation des structures et des threads */

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	rules->forks = malloc(sizeof(pthread_mutex_t));
	if (!(rules->forks))
		return (1);
	while (--i >= 0) /* initialize one mutex per fork so one mutex per philo */
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->writing), NULL)) /* Initiliaze one mutex for the writing variable as we need to wait for thread to be exec completly when writing*/
		return (1);
	if (pthread_mutex_init(&(rules->meal), NULL))
		return (1);
	return (0);
}

int	init_philo(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	while (--i >= 0)
	{
		rules->philo[i].id = i;
		rules->philo[i].ate = 0;
		rules->philo[i].l_fork = i;
		rules->philo[i].r_fork = (i + 1) % rules->nb_philo; /* so the right forks as same id as previous one as its supposed to be the same one */
		rules->philo[i].tslm = 0;
		rules->philo[i].rules = rules;
	}
	return (0);
}

int	initialize(t_rules *rules, char **av) /* Initialize general rules and check for valid args */
{
	rules->nb_philo = ft_atoi(av[1]);
	rules->t_die = ft_atoi(av[2]);
	rules->t_eat = ft_atoi(av[3]);
	rules->t_sleep = ft_atoi(av[4]);
	rules->all_eaten = 0;
	rules->is_dead = 0;
	if (check_args(rules))
		return (1);
	if (av[5])
	{
		rules->to_eat = ft_atoi(av[5]);
		if (rules->to_eat <= 0)
			return (1);
	}
	else
		rules->to_eat = -1; /* optionnal argument is not present so set value to -1 */
	if (init_mutex(rules))
		return (MUTEX_ERR_CODE);
	init_philo(rules);
	return (0);
}
