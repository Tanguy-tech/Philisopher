/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tanguy <Tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:50:51 by Tanguy            #+#    #+#             */
/*   Updated: 2021/12/01 11:07:55 by Tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_error(char  *err_msg)
{
    int l;

    l = 0;
    while (err_msg[l])
        l++;
    write(1, err_msg, l);
    write(1, "\n", 1);
    return (1);
}

int	error_manager(int err)
{
	if (err == ARGS_ERR_CODE)
		return (display_error(ARGS_ERROR));
    if (err == MUTEX_ERR_CODE)
        return (display_error(MUTEX_ERROR));
    if (err == THREAD_ERR_CODE)
        return (display_error(THREAD_ERROR));
    return (1);
}

int check_args(t_rules *rules)
{
    if (rules->nb_philo < 2 || rules->t_die < 0 || rules->t_eat < 0
		|| rules->t_sleep < 0)
        return (1);
    return (0);
}