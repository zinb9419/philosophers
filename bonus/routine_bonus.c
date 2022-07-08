/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:29:45 by ziloughm          #+#    #+#             */
/*   Updated: 2022/07/08 00:04:47 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_eating(t_philo **phi, t_data *data)
{
	int				id;

	sem_wait(data->eating);
	id = (*phi)->id_philo;
	sem_post(data->eating);
	sem_wait(data->forks);
	ft_print_msg(phi, "has taking a fork 1", data);
	sem_wait(data->forks);
	ft_print_msg(phi, "has taking a fork 2", data);
	ft_print_msg(phi, "is eating", data);
	sem_wait(data->eating);
	(*phi)->last_eat = get_time();
	sem_post(data->eating);
	ft_usleep(data->t_eat);
	sem_wait(data->eating);
	++(*phi)->nb_eating;
	sem_post(data->eating);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	ft_sleeping(t_philo **phi, t_data *data)
{
	ft_print_msg(phi, "is sleeping", data);
	ft_usleep(data->t_sleep);
}

void	ft_thinking(t_philo **phi, t_data *data)
{
	ft_print_msg(phi, "is thinking", data);
}

/*int	ft_check_die(t_philo *phi)
{
	sem_wait(&(phi->data->eating));
	sem_wait(&(phi->data->print_msg));
	if ((get_time() - phi->last_eat) >= phi->data->t_die)
	{
		printf("%s%ld %s%d %sis died%s\n", B, get_time() - phi->data->t_now, \
			G, phi->id_philo + 1, RED, WHITE);
		return (1);
	}
	sem_post(&phi->data->eating);
	sem_post(&(phi->data->print_msg));
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
		sem_wait(&(phi->data->eating));
		sem_wait(&(phi->data->print_msg));
		if ((phi + i)->nb_eating >= data->nb_eating)
			nb++;
		sem_post(&(phi->data->eating));
		sem_post(&(phi->data->print_msg));
		i++;
	}
	sem_wait(&(phi->data->eating));
	sem_wait(&(phi->data->print_msg));
	if (nb >= data->nb_philo && data->nb_eating != -1)
		return (1);
	sem_post(&(phi->data->eating));
	sem_post(&(phi->data->print_msg));
	return (0);
}*/
