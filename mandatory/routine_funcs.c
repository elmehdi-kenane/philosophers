/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:27:08 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/12 21:31:06 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *current, t_state state)
{
	pthread_mutex_lock(&(current->table->print));
	if (state == TAKE_FORK)
		printf("%ld\t %d has taken a fork\n",
			timey() - current->table->initial_time, current->philo_id);
	else if (state == EATING)
		printf("%ld\t %d is eating\n",
			timey() - current->table->initial_time, current->philo_id);
	else if (state == SLEEPING)
		printf("%ld\t %d is sleeping\n",
			timey() - current->table->initial_time, current->philo_id);
	else if (state == THINKING)
		printf("%ld\t %d is thinking\n",
			timey() - current->table->initial_time, current->philo_id);
	else if (state == DIED)
		printf("%ld \t %d died\n",
			(timey() - current->table->initial_time), current->philo_id);
	pthread_mutex_unlock(&(current->table->print));
}

void	sleeping_thinking_func(t_philo *current)
{
	print_msg(current, SLEEPING);
	usleep_remake(current->table->time_to_sleep * 1000);
	print_msg(current, THINKING);
}

void	max_meals(t_philo *current)
{
	pthread_mutex_lock(&current->finish_eat);
	current->finished = 1;
	pthread_mutex_unlock(&current->finish_eat);
}

void	eating_func(t_philo *current)
{
	pthread_mutex_lock(&current->fork);
	print_msg(current, TAKE_FORK);
	pthread_mutex_lock(&current->next->fork);
	print_msg(current, TAKE_FORK);
	print_msg(current, EATING);
	pthread_mutex_lock(&current->m_last_meal);
	current->last_meal = timey();
	pthread_mutex_unlock(&current->m_last_meal);
	usleep_remake((current->table->time_to_eat * 1000));
	pthread_mutex_unlock(&current->fork);
	pthread_mutex_unlock(&current->next->fork);
}

void	*func(void *arg)
{
	t_philo	*current;
	int		i;

	current = (t_philo *)arg;
	pthread_mutex_lock(&current->m_last_meal);
	current->last_meal = timey();
	pthread_mutex_unlock(&current->m_last_meal);
	if ((current->philo_id % 2) == 0)
		usleep(100);
	i = 1;
	while (1)
	{
		eating_func(current);
		if (i == current->table->optional_argument)
		{
			max_meals(current);
			break ;
		}
		i++;
		sleeping_thinking_func(current);
	}
	return (NULL);
}
