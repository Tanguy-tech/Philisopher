/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tanguy <Tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:25:00 by Tanguy            #+#    #+#             */
/*   Updated: 2021/12/09 09:01:49 by Tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> /* printf function */
# include <pthread.h> /* thread handling */
# include <string.h> /* memset function */
# include <stdlib.h> /* malloc and free function */
# include <unistd.h> /* write function */
# include <sys/time.h> /* time handling functions */

# define ARGS_ERR_CODE 1
# define ARGS_ERROR "ARGUMENTS ERRORS! ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]"
# define ARGS_NUM "Wrong number of arguments!"
# define MUTEX_ERR_CODE 2
# define MUTEX_ERROR "MUTEX ERROR! There was an error initialazing the mutex."
# define THREAD_ERR_CODE 3
# define THREAD_ERROR "TH ERROR! There was an error when creating the threads."
# define TAKE_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIES "died"

typedef struct s_philo
{
	int				id; /* identifier of current philo */
	int				l_fork; /* left fork - if 1 fork is in hand */
	int				r_fork; /* right fork - if 1 fork is in hand */
	int				ate; /* amount ate by the philo - plays its role if option is specified */
	long long		tslm; /* time since last meal */
	struct s_rules 	*rules; /* games rules structure - got all the infos about the current game */
	pthread_t		th_id; /* thread id of current philo */
}				t_philo;

typedef struct s_rules
{
	int				nb_philo; /* number of philospher to seat around the table */
	int				t_die; /* time not to go over between each meal otherwise, philo dies */
	int				t_eat; /* time it takes a philo to eat */
	int				t_sleep; /* time it takes a philo to sleep */
	int				is_dead; /* is philo dead or alive */
	int				to_eat; /* max amount to be eaten by philos */
	pthread_mutex_t	*forks; /* forks protected by mutexes to not overcross eachother */
	pthread_mutex_t	writing; /* writing protected by mutexes to wait until writing is done before executing next step (to no continue if someone dies) */
	pthread_mutex_t	meal;
	t_philo			philo[250]; /* philo structure contains the philos */
	long long		initial_time; /* initial time when prog start */
	int				all_eaten;
}				t_rules;

int			initialize(t_rules *rules, char **av);
int			run(t_rules *rules);
int			display_error(char *err_msg);
int			error_manager(int err);
int			check_args(t_rules *rules);
int			ft_atoi(const char *str);
long long	timestamp(void);
long long	diff_time(long long past, long long pres);
void		display_events(t_rules *rules, int id, char *message);
void		philo_sleep(long long time, t_rules *rules);

#endif