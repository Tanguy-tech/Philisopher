/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tanguy <Tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:40:06 by Tanguy            #+#    #+#             */
/*   Updated: 2021/12/01 12:21:26 by Tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;
	int		throw;

	if (ac != 5 && ac != 6)
		return (display_error(ARGS_NUM));
	if ((throw = initialize(&rules, av))) /* throw is gonna be equal to the return result of the "initialize()" function - either 1 ou 2 */
		return (error_manager(throw));
	if (run(&rules))
		return (error_manager(THREAD_ERR_CODE));
	return (0);
}