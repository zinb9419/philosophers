/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:57:46 by ziloughm          #+#    #+#             */
/*   Updated: 2022/07/08 01:22:04 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*int	ft_chekcer(t_philo *philo, t_data *data)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->nb_philo)
		{
			if (ft_check_meals(philo, data) == 1 || \
				ft_check_die(philo + i) == 1)
				return (1);
		}
		usleep(50);
	}
	return (0);
}

void	ft_destroy(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&(data->print_msg));
	pthread_mutex_destroy(&(data->eating));
	while (++i < data->nb_philo)
	{
		pthread_detach((philo + i)->thread);
		pthread_mutex_destroy(&(data->forks[i]));
	}
}*/

void	*routine(void *ph)
{
	t_philo		*phi;

	phi = (t_philo *)ph;
	while (1)
	{
		ft_eating(&phi, phi->data);
		ft_sleeping(&phi, phi->data);
		ft_thinking(&phi, phi->data);
	}
	return (NULL);
}

void	ft_init(t_philo *philo, t_data *data, int i)
{
	while (++i < data->nb_philo)
	{
		philo[i].data = data;
		philo[i].id_philo = i;
		philo[i].nb_eating = 0;
		philo[i].last_eat = get_time();
	}
}

void	ft_philosophers(t_data *data)
{
	t_philo			*philo;
	int				i;

	philo = malloc(sizeof(t_philo) * data->nb_philo);
	i = -1;
	if (!philo)
		ft_error("Faild to allocate for philosophers");
	sem_unlink("print_msg");
	sem_unlink("eating");
	sem_unlink("forks");
	data->print_msg = sem_open("print_msg", 0777, 1);
	data->eating = sem_open("eating", 0777, 1);
	data->forks = sem_open("forks", 0777, data->nb_philo);
	ft_init(philo, data, -1);
	ft_init2(philo, data);
	sem_close(data->print_msg);
	sem_close(data->eating);
	sem_close(data->forks);
	while (++i < data->nb_philo)
	{
		waitpid((philo + i)->pid, NULL, 0);
		i++;
	}
}
