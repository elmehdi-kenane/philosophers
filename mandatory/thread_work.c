/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:50:32 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/13 00:25:21 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_eating(t_philo *head)
{
	int		i;
	t_philo	*current;

	i = 0;
	current = head;
	while (i < head->table->num_philos)
	{
		pthread_mutex_init(&current->fork, NULL);
		pthread_mutex_init(&current->m_last_meal, NULL);
		pthread_mutex_init(&current->finish_eat, NULL);
		if (pthread_create(&current->philos, NULL, func, current))
			return (0);
		current = current->next;
		i++;
	}
	pthread_mutex_init(&current->table->print, NULL);
	return (1);
}

int	detach_philos(t_philo *head)
{
	int		i;
	t_philo	*current;

	i = 0;
	current = head;
	while (i < head->table->num_philos)
	{
		if (pthread_detach(current->philos))
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

void	died_or_finish(t_philo *head)
{
	t_philo	*current;
	int		i;
	time_t	last_meal;

	while (1)
	{
		current = head;
		i = 0;
		while (i < head->table->num_philos)
		{
			pthread_mutex_lock(&current->m_last_meal);
			last_meal = current->last_meal;
			pthread_mutex_unlock(&current->m_last_meal);
			if ((timey() - last_meal) >= current->table->time_to_die)
			{
				print_msg(current, DIED);
				pthread_mutex_lock(&current->table->print);
				return ;
			}
			current = current->next;
			i++;
		}
		if (philos_is_finished(head) == 1)
			return ;
	}
}

int	philos_is_finished(t_philo *head)
{
	int	i;

	i = 0;
	while (i < head->table->num_philos)
	{
		pthread_mutex_lock(&head->finish_eat);
		if (head->finished == 0)
		{	
			pthread_mutex_unlock(&head->finish_eat);
			return (0);
		}
		pthread_mutex_unlock(&head->finish_eat);
		head = head->next;
		i++;
	}
	return (1);
}
