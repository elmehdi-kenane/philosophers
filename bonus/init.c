/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:01:22 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/13 00:32:26 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	routine_func(t_philo *philo)
{
	philo->meals = 0;
	philo->last_meal = timey();
	if ((philo->philo_id % 2) == 0)
		usleep(100);
	while (1)
	{
		sem_wait(philo->table.forks);
		print_msg(philo, TAKE_FORK);
		sem_wait(philo->table.forks);
		print_msg(philo, TAKE_FORK);
		print_msg(philo, EATING);
		philo->last_meal = timey();
		usleep_remake(philo->table.time_to_eat * 1000);
		philo->meals++;
		sem_post(philo->table.forks);
		sem_post(philo->table.forks);
		if (philo->meals == philo->table.optional_argument)
			exit(0);
		print_msg(philo, SLEEPING);
		usleep_remake(philo->table.time_to_sleep * 1000);
		print_msg(philo, THINKING);
	}
	return (0);
}

int	init_sem(t_table *table)
{
	sem_unlink("_forks");
	sem_unlink("_print");
	(*table).forks = sem_open("_forks", O_CREAT, 777, (*table).num_philos);
	(*table).print = sem_open("_print", O_CREAT, 777, 1);
	(*table).pids = malloc(sizeof(int) * (*table).num_philos);
	if (!(*table).pids)
		return (0);
	if ((*table).forks == SEM_FAILED || (*table).print == SEM_FAILED)
		return (0);
	return (1);
}

int	init_func(t_table *table)
{
	t_philo	philo;
	int		i;

	(*table).initial_time = timey();
	i = 0;
	while (i < (*table).num_philos)
	{
		(*table).pids[i] = fork();
		if ((*table).pids[i] == -1)
			exit(1);
		else if ((*table).pids[i] == 0)
		{
			philo.table = (*table);
			philo.philo_id = i + 1;
			pthread_create(&(*table).monitor, NULL, monitoring, &philo);
			if (pthread_detach((*table).monitor) != 0)
				return (0);
			routine_func(&philo);
		}
		i++;
	}
	return (1);
}
