/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:29:45 by ziloughm          #+#    #+#             */
/*   Updated: 2022/07/02 18:44:08 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo **phi)
{
	int				id;

	pthread_mutex_lock(&((*phi)->data->eating));
	id = (*phi)->id_philo;
	pthread_mutex_unlock(&((*phi)->data->eating));
	pthread_mutex_lock(&((*phi)->data->forks[id]));
	ft_print_msg(phi, "has taking a fork 1");
	pthread_mutex_lock(&((*phi)->data->forks[(id + 1) % \
		(*phi)->data->nb_philo]));
	ft_print_msg(phi, "has taking a fork 2");
	ft_print_msg(phi, "is eating");
	pthread_mutex_lock(&((*phi)->data->eating));
	(*phi)->last_eat = get_time();
	pthread_mutex_unlock(&((*phi)->data->eating));
	ft_usleep((*phi)->data->t_eat);
	pthread_mutex_lock(&((*phi)->data->eating));
	++(*phi)->nb_eating;
	pthread_mutex_unlock(&((*phi)->data->eating));
	pthread_mutex_unlock(&((*phi)->data->forks[id]));
	pthread_mutex_unlock(&((*phi)->data->forks[(id + 1) % \
		(*phi)->data->nb_philo]));
}

void	ft_sleeping(t_philo **phi)
{
	ft_print_msg(phi, "is sleeping");
	ft_usleep((*phi)->data->t_sleep);
}

void	ft_thinking(t_philo **phi)
{
	ft_print_msg(phi, "is thinking");
}

int	ft_check_die(t_philo *phi)
{
	pthread_mutex_lock(&(phi->data->eating));
	pthread_mutex_lock(&(phi->data->print_msg));
	if ((get_time() - phi->last_eat) >= phi->data->t_die)
	{
		printf("%s%ld %s%d %sis died%s\n", B, get_time() - phi->data->t_now, \
			G, phi->id_philo + 1, RED, WHITE);
		return (1);
	}
	pthread_mutex_unlock(&phi->data->eating);
	pthread_mutex_unlock(&(phi->data->print_msg));
	return (0);
}

int	ft_check_meals(t_philo *phi, t_data *data)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&(phi->data->eating));
		pthread_mutex_lock(&(phi->data->print_msg));
		if ((phi + i)->nb_eating >= data->nb_eating)
			nb++;
		pthread_mutex_unlock(&(phi->data->eating));
		pthread_mutex_unlock(&(phi->data->print_msg));
		i++;
	}
	pthread_mutex_lock(&(phi->data->eating));
	pthread_mutex_lock(&(phi->data->print_msg));
	if (nb >= data->nb_philo && data->nb_eating != -1)
		return (1);
	pthread_mutex_unlock(&(phi->data->eating));
	pthread_mutex_unlock(&(phi->data->print_msg));
	return (0);
}
