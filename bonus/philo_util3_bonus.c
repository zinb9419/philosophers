/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:50:40 by ziloughm          #+#    #+#             */
/*   Updated: 2022/07/08 01:29:12 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init2(t_philo *philo, t_data *data)
{
	int		i;
	pid_t	pid;

	i = 0;
	data->t_now = get_time();
	while (i < data->nb_philo)
	{
		pid = fork();
		if (pid == 0)
		{
			routine(&philo[i]);
			return ;
		}
		i++;
		usleep(100);
	}
}
