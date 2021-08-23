/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:36:09 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/23 10:10:44 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_data(t_data *data, int ac, char **av)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (ERROR);
	data->nb_of_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->one_died = FALSE;
	if (ac == 6)
	{
		data->meals = 1; /* bool to true beacuse number of meals is specified */
		data->amount_to_eat = ft_atoi(av[5]);
	}
	else
	{
		data->meals = 0; /* boolean to false */
		data->amount_to_eat = 0;
	}
	return (SUCCESS);
}

int	init_philo(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	// init mutex fork ??
	// init mutex display ??
	philo = malloc(sizeof(t_philo) * nb_philo);
	if (!philo)
		return (ERROR);
	while (i < nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].is_dead = 0;
		philo[i].last_meal = 0;
		i++;
	}
	return (SUCCESS);
}
