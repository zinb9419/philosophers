/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:23:37 by ziloughm          #+#    #+#             */
/*   Updated: 2022/07/02 21:57:58 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 5 || ac > 6)
		printf("%sAttention! %sthe number of parameters invalid\n", RED, WHITE);
	else
	{
		data = ft_check_params(av);
		if (!data)
		{
			free(data);
			return (1);
		}
		else
			ft_philosophers(data);
	}
	return (0);
}
