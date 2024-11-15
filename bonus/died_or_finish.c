/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died_or_finish.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:13:05 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/13 00:37:17 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = timey();
	while (1)
	{
		if (timey() - philo->last_meal >= philo->table.time_to_die)
		{
			sem_wait(philo->table.print);
			print_msg(philo, DIED);
			exit(1);
		}
	}
}

void	free_resources(t_table table)
{
	free(table.pids);
	sem_close(table.forks);
	sem_close(table.print);
}

void	philo_died(t_table table)
{
	int	i;

	i = 0;
	while (i < table.num_philos)
	{
		kill(table.pids[i], SIGKILL);
		i++;
	}
	free_resources(table);
}

void	finish_meals(t_table table, pid_t return_pid)
{
	int	i;

	i = 0;
	while (i < table.num_philos)
	{
		if (table.pids[i] != return_pid)
			waitpid(table.pids[i], NULL, 0);
		i++;
	}
	free_resources(table);
}
