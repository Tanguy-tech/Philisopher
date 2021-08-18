/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:26:39 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/18 09:31:18 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int main(int ac, char **av)
{
    t_global    *global;
    t_data      *data;
    t_philo     *philo;
    
    if (format_errors(ac, av) == ERROR) // if all checks failed
        return (ERROR);
    // initialiser strucutre et lancer programme
    return (0);
}
