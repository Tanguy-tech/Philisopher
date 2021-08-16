/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:27:08 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/16 09:27:38 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
