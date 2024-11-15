/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 01:21:58 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/13 00:13:10 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_struct(t_philo *head, t_table *table)
{
	t_philo	*current;
	t_philo	*tmp;
	int		i;

	current = head;
	i = head->table->num_philos;
	free(table);
	while (i > 0)
	{
		pthread_mutex_destroy(&current->finish_eat);
		pthread_mutex_destroy(&current->fork);
		pthread_mutex_destroy(&current->m_last_meal);
		tmp = current;
		current = current->next;
		free(tmp);
		i--;
	}
}

int	main(int ac, char *av[])
{
	t_philo		*head;
	t_table		*table;

	table = NULL;
	if (check_all(ac, av, &table))
		return (1);
	head = set_table(table);
	table->initial_time = timey();
	if (!start_eating(head))
		return (1);
	if (!detach_philos(head))
		return (1);
	died_or_finish(head);
	free_struct(head, table);
	return (0);
}
