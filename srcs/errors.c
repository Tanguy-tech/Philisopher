/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:36:30 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/18 09:27:15 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int format_errors(int ac, char **av)
{
    int i;

    i = 1;
    if (ac != 5 && ac != 6)
        return (display_error("ERROR: Wrong number fo args\n", 28)); /* if arguments are not 5 of 6 then display this error */
    if (ft_atoi(av[1]) < 2)
        return (display_error("ERROR: Not enough philosophers\n", 53)); /* can't launch with less than 2 philosophers */
    if (ac == 6 && ft_atoi(av[5]) < 1)
        return (display_error("ERROR: Not enough meals (at least 1)\n", 39)); /* if meals is specified, it has to be at least 1 */
    while (av[i])
    {
        if (ft_atoi(av[i]) <= 0)
            return (display_error("ERROR: args must be numbers only\n", 38)); /* all args must be numbers only in order to work properly */
        i++;
    }
    return (SUCCESS);
}

int display_error(char *error_msg, int msg_len)
{
    write(1, error_msg, msg_len);
    return (ERROR);
}
