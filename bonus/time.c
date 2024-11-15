/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:32:59 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/12 20:43:15 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

time_t	timey(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		exit(1);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

void	usleep_remake(long int wait_time)
{
	long int	first_time;

	first_time = timey();
	usleep(wait_time * 0.9);
	while (timey() - first_time <= (wait_time / 1000))
		usleep(wait_time / 100);
}
