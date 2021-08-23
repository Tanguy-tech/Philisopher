/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:58:51 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/23 10:15:33 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	routine(void *global)
{
	int			i;
	t_global	*glob;
	t_data		*data;
	t_philo		*philo;

	i = 0;
	glob = (t_global *)global;
	data = glob->data;
	philo = glob->philo;
	while (!data->one_died && (data->meals || i < data->amount_to_eat))
	{
        // routine of the life of the philosopher
        // create threads 
        // philo takes forks
        // philo action eat
        // philo action sleep
        // philo action think 
		i++;
	}
    // death of a philo 
}

int	launch(t_global *global, t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		global[i].philo = &philo[i];
		global[i].data = data;
		pthread_create(&philo[i].th_id, NULL, &routine, &global[i]);
		i++;
	}
	return (SUCCESS);
}

void	free_philo(t_data *data, t_philo *philo)
{
    // destroy mutex display
	free(philo);
	free(data);
}
