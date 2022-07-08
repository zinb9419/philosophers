/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:23:57 by ziloughm          #+#    #+#             */
/*   Updated: 2022/07/08 01:18:50 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

//Libraries
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

//Struct

typedef struct s_data
{
	int				nb_philo;
	long int		t_now;
	int				t_eat;
	int				t_die;
	int				t_sleep;
	int				nb_eating;
	int				is_died;
	int				result;
	sem_t			*forks;
	sem_t			*print_msg;
	sem_t			*eating;
	sem_t			*stop;
}t_data;

typedef struct s_philo
{
	pthread_t		thread;
	t_data			*data;
	long int		last_eat;
	int				nb_eating;
	int				id_philo;
	pid_t			pid;
}t_philo;

//Colors
# define RED "\x1B[31m"
# define WHITE "\x1B[37m"
# define PURPLE "\033[0;35m"
# define B "\033[0;33m"
# define G "\033[0;32m"
# define BOLD "\e[1m"
# define BOLD_OFF "\e[m"

//Check the parameters
int			ft_atoi(const char *str);
t_data		*ft_check_params(char **av);

//Util function
long int	get_time(void);
void		ft_error(char *msg);
void		ft_usleep(long int to_sleep);
void		ft_print_msg(t_philo **phi, char *msg, t_data *data);

//Routine function
void		ft_eating(t_philo **philo, t_data *data);
void		ft_sleeping(t_philo **philo, t_data *data);
void		ft_thinking(t_philo **philo, t_data *data);
int			ft_check_die(t_philo *phi);
int			ft_check_meals(t_philo *phi, t_data *data);
void		*routine(void *ph);
void		ft_init(t_philo *philo, t_data *data, int i);
void		ft_init2(t_philo *philo, t_data *data);
void		ft_philosophers(t_data *data);

//Simulation
int			ft_chekcer(t_philo *philo, t_data *data);
void		ft_destroy(t_philo *philo, t_data *data);

#	endif