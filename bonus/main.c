/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 01:21:58 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/13 00:27:31 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	elmehdi(void)
{
	system("leaks philo");
}

void	print_msg(t_philo *current, t_state state)
{
	if (state == DIED)
		printf("%ld \t %d died\n",
			(timey() - current->table.initial_time), current->philo_id);
	else
	{
		sem_wait(current->table.print);
		if (state == TAKE_FORK)
			printf("%ld\t %d has taken a fork\n",
				timey() - current->table.initial_time, current->philo_id);
		else if (state == EATING)
			printf("%ld\t %d is eating\n",
				timey() - current->table.initial_time, current->philo_id);
		else if (state == SLEEPING)
			printf("%ld\t %d is sleeping\n",
				timey() - current->table.initial_time, current->philo_id);
		else if (state == THINKING)
			printf("%ld\t %d is thinking\n",
				timey() - current->table.initial_time, current->philo_id);
		sem_post(current->table.print);
	}
}

int	main(int ac, char *av[])
{
	t_table		table;
	int			status;
	pid_t		return_pid;

	if (check_all(ac, av, &table))
		return (0);
	if (!init_sem(&table) || !init_func(&table))
		return (1);
	return_pid = waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 1)
		philo_died(table);
	else if (WEXITSTATUS(status) == 0)
		finish_meals(table, return_pid);
	atexit(elmehdi);
	return (0);
}
