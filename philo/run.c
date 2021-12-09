/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tanguy <Tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:08:22 by Tanguy            #+#    #+#             */
/*   Updated: 2021/12/09 08:25:30 by Tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_eat(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->l_fork]));
	display_events(rules, philo->id, TAKE_FORK);
	pthread_mutex_lock(&(rules->forks[philo->r_fork]));
	display_events(rules, philo->id, TAKE_FORK);
	pthread_mutex_lock(&(rules->meal));
	display_events(rules, philo->id, EAT);
	philo->tslm = timestamp(); /* Set time since last meal to current time as philo just ate */
	pthread_mutex_unlock(&(rules->meal));
	philo_sleep(rules->t_eat, rules);
	(philo->ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->l_fork]));
	pthread_mutex_unlock(&(rules->forks[philo->r_fork]));
}

void	death(t_rules *rules, t_philo *philo)
{
	int	i;

	while (!(rules->all_eaten)) /* while everything hasn't been eaten */
	{
		i = -1;
		while (++i < rules->nb_philo && !(rules->is_dead))
		{
			pthread_mutex_lock(&(rules->meal));
			if (diff_time(philo[i].tslm, timestamp()) > rules->t_die)
			{
				display_events(rules, i, DIES);
				rules->is_dead = 1; /* A philosopher has died */
			}
			pthread_mutex_unlock(&(rules->meal));
			usleep(100);
		}
		if (rules->is_dead)
			break ;
		i = 0;
		while (rules->to_eat != -1 && i < rules->nb_philo && philo[i].ate >= rules->to_eat)
			i++;
		if (i == rules->nb_philo)
			rules->all_eaten = 1;
	}
}

void	quit(t_rules *rules, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
		pthread_join(philo[i].th_id, NULL);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writing));
}

void	*create_thread(void *param_philo)
{
	int		i;
	t_philo	*philo;
	t_rules	*rules;

	i = 0;
	philo = (t_philo *)param_philo;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->is_dead))
	{
		action_eat(philo);
		if (rules->all_eaten)
			break ;
		display_events(rules, philo->id, SLEEP);
		philo_sleep(rules->t_sleep, rules);
		display_events(rules, philo->id, THINK);
		i++;
	}
	return (NULL);
}

int	run(t_rules *rules)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = rules->philo;
	rules->initial_time = timestamp();
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(philo[i].th_id), NULL, create_thread, &(philo[i])))
			return (1);
		philo[i].tslm = timestamp(); /* set last meal to current time */
		i++;
	}
	death(rules, rules->philo);
	quit(rules, philo);
	free(rules->forks);
	return (0);
}
