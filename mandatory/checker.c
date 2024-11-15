/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 02:08:39 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/08 17:44:14 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	a_to_int(t_table *table, char *av[], int ac)
{
	table->num_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		table->optional_argument = ft_atoi(av[5]);
		if (table->optional_argument <= 0)
			table->optional_argument = 0;
	}
	else
		table->optional_argument = -1;
}

int	check_input(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][0] == '+' || ft_isdigit(av[i][j]))
				j++;
			else
			{
				printf("error input number\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
}

int	check_all(int ac, char *av[], t_table **table)
{
	if (ac < WITHOUT_MAX || ac > WITH_MAX)
		return (print_error("bad number of arguments\n"), 1);
	if (check_input(ac, av))
		return (1);
	(*table) = malloc(sizeof(t_table));
	if (!table)
		return (1);
	a_to_int((*table), av, ac);
	if ((*table)->num_philos <= 0 || (*table)->optional_argument == 0)
		return (print_error("there's no philosopher OR simulation error\n"), 1);
	return (0);
}
