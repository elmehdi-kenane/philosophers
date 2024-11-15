/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:43:50 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/12 22:53:59 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_list(int value, t_table *table)
{
	t_philo	*head;

	head = malloc(sizeof(t_philo));
	if (!head)
		return (NULL);
	head->philo_id = value;
	head->died = 0;
	head->finished = 0;
	head->table = table;
	head->next = NULL;
	return (head);
}

t_philo	*addnode_at_tail(t_philo *head, int value, t_table *table)
{
	t_philo	*new_node;
	t_philo	*current;

	current = head;
	if (head == NULL)
	{
		head = new_list(value, table);
		return (head);
	}
	else
	{
		new_node = malloc(sizeof(t_philo));
		if (!new_node)
			return (NULL);
	}
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->philo_id = value;
	new_node->died = 0;
	new_node->finished = 0;
	new_node->table = table;
	new_node->next = NULL;
	return (head);
}

t_philo	*set_table(t_table *table)
{
	t_philo	*head;
	t_philo	*current;
	int		i;

	head = NULL;
	i = 1;
	while (i <= table->num_philos)
	{
		head = addnode_at_tail(head, i, table);
		i++;
	}
	current = head;
	while (current->next)
		current = current->next;
	current->next = head;
	return (head);
}

time_t	timey(void)
{
	struct timeval	time;
	time_t			return_value;

	if (gettimeofday(&time, NULL) != 0)
		exit(1);
	return_value = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (return_value);
}

void	usleep_remake(long int wait_time)
{
	long int	first_time;

	first_time = timey();
	while (timey() - first_time <= (wait_time / 1000))
		usleep(wait_time / 100);
}
