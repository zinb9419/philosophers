/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:00:44 by ziloughm          #+#    #+#             */
/*   Updated: 2022/06/25 18:20:17 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_atoi(char c, char *s)
{
	if (c)
	{
		printf("%sError: %s%s%s > ", RED, BOLD, s, BOLD_OFF);
		printf("%sIt is necessary to pass only numerical parameters\n", WHITE);
		return (-1);
	}
	return (1);
}

static int	ft_check_int(long double n, char c, char *s)
{
	if (ft_check_atoi(c, s) < 0)
		return (-1);
	if (n > 2147483647 || n <= 0)
	{
		printf("%sError: %s%s%s > ", RED, BOLD, s, BOLD_OFF);
		printf("%sYou must pass a strictly positive numeric parameter\n", WHITE);
		return (-1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long double	n;
	long double	m;
	int			i;
	char		*s;

	n = 0;
	i = 0;
	m = 1;
	s = (char *)str;
	if (s[i] == '-')
		m = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= 48 && s[i] <= 57)
	{
		n = (long double) n * 10;
		n = n + s[i] - 48;
		i++;
	}
	if (ft_check_int(n * m, s[i], s) < 0)
		return (-1);
	return (n);
}

static int	ft_init_data(t_data **data, int i, int nb)
{
	if (nb < 0)
		return (-1);
	if (i == 1)
		(*data)->nb_philo = nb;
	else if (i == 2)
		(*data)->t_die = nb;
	else if (i == 3)
		(*data)->t_eat = nb;
	else if (i == 4)
		(*data)->t_sleep = nb;
	if (i == 5)
		(*data)->nb_eating = nb;
	return (0);
}

t_data	*ft_check_params(char **av)
{
	int		i;
	int		nb;
	t_data	*data;

	i = 1;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		ft_error("Allocation error");
		return (NULL);
	}
	data->nb_eating = -1;
	while (av[i])
	{
		nb = ft_init_data(&data, i, ft_atoi(av[i]));
		if (nb < 0)
		{
			free(data);
			return (NULL);
		}
		i++;
	}
	return (data);
}
