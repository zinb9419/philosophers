/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:58:52 by ziloughm          #+#    #+#             */
/*   Updated: 2022/07/08 00:04:14 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	get_time(void)
{
	struct timeval		t;

	gettimeofday (&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_usleep(long int to_sleep)
{
	long int	now;

	now = get_time();
	usleep(to_sleep * 800);
	while ((get_time() - now) < to_sleep)
		usleep(250);
}

void	ft_error(char *msg)
{
	if (msg)
		printf("%s%s%s\n", RED, msg, WHITE);
}

void	ft_print_msg(t_philo **phi, char *msg, t_data *data)
{
	if (msg)
	{
		sem_wait(data->print_msg);
		printf("%s%ld %s%d %s%s\n", B, get_time() - data->t_now, \
			G, (*phi)->id_philo + 1, WHITE, msg);
		sem_post(data->print_msg);
	}
}
