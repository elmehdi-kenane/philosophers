/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 03:19:18 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/12 22:44:14 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
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
	pthread_mutex_t	print;
	pthread_mutex_t	eating;
	int				optional_argument;
}					t_table;

typedef struct philo
{
	pthread_t		philos;
	t_table			*table;
	int				philo_id;
	int				finished;
	int				died;
	time_t			last_meal;
	pthread_mutex_t	fork;
	pthread_mutex_t	finish_eat;
	pthread_mutex_t	m_last_meal;
	struct philo	*next;
}		t_philo;

int		ft_atoi(const char *str);
t_philo	*set_table(t_table *table);
int		ft_isdigit(int a);
size_t	ft_strlen(const char *str);
int		check_all(int ac, char *av[], t_table **table);
void	*func(void *arg);
time_t	timey(void);
void	usleep_remake(long int wait_time);
int		start_eating(t_philo *head);
void	print_msg(t_philo *current, t_state state);
int		philos_is_finished(t_philo *head);
int		detach_philos(t_philo *head);
void	died_or_finish(t_philo *head);
#endif