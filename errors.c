/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:36:30 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/16 10:13:08 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int error_check(int ac, char **av)
{
    int i;

    i = 1;
    if (ac != 5 && ac != 6)
        return (display_error("ERROR: Wrong number fo args\n", 28));
    if (ft_atoi(av[1]) < 2)
        return (display_error("ERROR: Not enough philosophers\n", 53));
    while (av[i])
    {
        if (ft_atoi(av[i]) <= 0)
            return (display_error("ERROR: arguments must be numbers only\n", 38));
        i++;
    }
    return (1);
}

int display_error(char *error_msg, int msg_len)
{
    write(1, error_msg, msg_len);
    return (-1);
}
