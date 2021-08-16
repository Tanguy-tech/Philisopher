/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:27:52 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/16 10:11:05 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct  s_philo
{
    int         id;
    int         l_fork;
    int         r_fork;
    int         amount_ate;
    long long   last_meal;
    pthread_t   th_id;
}               t_philo;

typedef struct  s_args
{
    int         t_die;
    int         t_eat;
    int         t_sleep;
    int         amount_to_eat;
    int         nb_of_philo;
    long long   timestamp;
    t_philo     *philo;
}               t_args;

int	ft_atoi(const char *str);

/*  ERRORS  */
int error_check(int ac, char **av);

#endif