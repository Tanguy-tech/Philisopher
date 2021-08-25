/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:48:23 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/25 09:03:21 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	takes_fork(t_global *global, t_philo *philo)
{
    // philo takes one fork
    // mutex lock for fork 1 
    pthread_mutex_lock(philo->r_fork);
    // philo takes the other fork
    // mutex lock for fork 2
    pthread_mutex_lock(philo->l_fork);
    // mutex lock display
    pthread_mutex_lock(philo->display);
    // call display for this event (cf philo.h)
    // mutex unlock display 
}

void	eat()
{
    // philo eats with two hands so two forks 
    // mutex lock display
    // call display for this event (cf philo.h)
}

void	sleep()
{

}

void	think()
{

}

void	die()
{

}
