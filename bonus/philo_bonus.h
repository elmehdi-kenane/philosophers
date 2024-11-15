/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:19:18 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/12 21:23:04 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define WITHOUT_MAX	5
# define WITH_MAX		6

typedef enum e_state
{
	TAKE_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}	t_state;

typedef struct table
{
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	time_t			initial_time;
	int				num_philos;
	int				*pids;
	int				optional_argument;
	sem_t			*print;
	sem_t			*forks;
	pthread_t		monitor;
}					t_table;

typedef struct philo
{
	t_table			table;
	int				philo_id;
	int				meals;
	time_t			last_meal;
}		t_philo;

int		ft_atoi(const char *str);
int		ft_isdigit(int a);
size_t	ft_strlen(const char *str);
int		check_all(int ac, char *av[], t_table *table);
time_t	timey(void);
void	usleep_remake(long int wait_time);
void	print_msg(t_philo *current, t_state state);
int		init_func(t_table *table);
int		init_sem(t_table *table);
void	*monitoring(void *arg);
void	finish_meals(t_table table, pid_t return_pid);
void	philo_died(t_table table);
#endif