/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:26:39 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/19 10:23:57 by tanguy           ###   ########.fr       */
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
    if (!init_data(data, ac, av)) // initialiser strucutre
        return (ERROR);
    if (!init_philo(philo, data->nb_of_philo)) // initialiser les philosophers
        return (ERROR);
    launch(global, data, philo);
    free_philo(data, philo);
    free(global);
    return (0);
}
