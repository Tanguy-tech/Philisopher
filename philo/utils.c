/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tanguy <Tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:16:40 by Tanguy            #+#    #+#             */
/*   Updated: 2021/12/09 08:28:48 by Tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned char	*str_;
	int				i;
	int				neg;
	int				res;

	i = 0;
	neg = 0;
	res = 0;
	str_ = (unsigned char *)str;
	while ((str_[i] >= 9 && str_[i] <= 13) || (str_[i] == 32))
		i++;
	if (str_[i] == '-' || str_[i] == '+')
		if (str_[i++] == '-')
			neg++;
	while (str_[i] >= 48 && str_[i] <= 57)
		res = res * 10 + (str_[i++] - 48);
	if (neg % 2 == 1)
		res = res * -1;
	return (res);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	diff_time(long long past, long long pres)
{
	return (pres - past);
}

void	philo_sleep(long long time, t_rules *rules)
{
	long long	i;

	i = timestamp();
	while (!(rules->is_dead))
	{
		if (diff_time(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}

void	display_events(t_rules *rules, int id, char *message)
{
	pthread_mutex_lock(&(rules->writing));
	if (!(rules->is_dead))
	{
		printf("%lli ", timestamp() - rules->initial_time);
		printf("%i ", id + 1);
		printf("%s\n", message);
	}
	pthread_mutex_unlock(&(rules->writing));
}
