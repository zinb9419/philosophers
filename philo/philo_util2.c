/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:57:46 by ziloughm          #+#    #+#             */
/*   Updated: 2022/07/02 16:10:15 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_chekcer(t_philo *philo, t_data *data)
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
}

void	*routine(void *ph)
{
	t_philo		*phi;

	phi = (t_philo *)ph;
	while (1)
	{
		ft_eating(&phi);
		ft_sleeping(&phi);
		ft_thinking(&phi);
	}
	return (NULL);
}

void	ft_init(t_philo *philo, t_data *data, int i)
{
	while (++i < data->nb_philo)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		philo[i].data = data;
		philo[i].id_philo = i;
		philo[i].nb_eating = 0;
		philo[i].last_eat = get_time();
	}
	i = 0;
	data->t_now = get_time();
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].thread), NULL, &routine, &philo[i]))
			ft_error("Faild to creat a thread");
		i += 2;
	}
	usleep(200 * data->nb_philo);
	i = 1;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].thread), NULL, &routine, &philo[i]))
			ft_error("Faild to creat a thread");
		i += 2;
	}
}

void	ft_philosophers(t_data *data)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		ft_error("Faild to allocate for philosophers");
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		ft_error("Faild to allocate for forks");
	pthread_mutex_init(&(data->print_msg), NULL);
	pthread_mutex_init(&(data->eating), NULL);
	ft_init(philo, data, -1);
	ft_chekcer(philo, data);
	ft_destroy(philo, data);
}
