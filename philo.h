/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:27:52 by tanguy            #+#    #+#             */
/*   Updated: 2021/08/25 09:03:32 by tanguy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

# define EVENT_FORK		"has taken a fork"
# define EVENT_EAT		"is eating"
# define EVENT_SLEEP	"is sleeping"
# define EVENT_THINK	"is thinking"
# define EVENT_DEAD		"is dead"

# define FALSE 0;
# define TRUE  1;

# define ERROR  -1
# define SUCCESS 1

typedef struct  s_philo
{
    int                     id; /* ID of the current philosopher */
    pthread_mutex_t         *l_fork; /* Left fork */
    pthread_mutex_t         *r_fork; /* Right fork */
    pthread_mutex_t         *display;
    int                     amount_ate; /* Amount already ate by the philosopher */
    int                     is_dead; /* is dead 1 or not 0 */
    long long               last_meal; /* Last meal ate */
    pthread_t               th_id; /* ID of the thread for the current philosopher */
}               t_philo;

typedef struct  s_data
{
    int         t_die; /* times to die */
    int         t_eat; /* times to eat */
    int         t_sleep; /* times to sleep */
    int         amount_to_eat; /* Amount to be eaten */
    int         nb_of_philo; /* Number of philosophers */
    int         one_died; /* if one philo die then turns to 1 */
    int         meals; /* if there is meals left */
    long long   timestamp;
    t_philo     *philo; /* Strucutre to philospher */
}               t_data;

typedef struct  s_global /* general structure to access all data */
{
    struct  s_data  *data;
    struct  s_philo *philo;
    
}               t_global;


/*  UTILS   */
int	ft_atoi(const char *str);
int	ft_strlen(char *s);

/*  ERRORS  */
int format_errors(int ac, char **av);
int display_error(char *error_msg, int msg_len);

/*  INIT    */
int    init_data(t_data *data, int ac, char **av);
int    init_philo(t_philo *philo, int nb_philo);

/*  DISPLAY */

/*  MAIN    */
int main(int ac, char **av);

/*  ACTIONS */

/*  PHILOSOPHER  */
void    routine(void *global);
int launch(t_global *global, t_data *data, t_philo *philo);
void    free_philo(t_data *data, t_philo *philo);

#endif