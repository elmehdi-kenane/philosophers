/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekenane <ekenane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:55:41 by ekenane           #+#    #+#             */
/*   Updated: 2023/06/10 12:07:41 by ekenane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	check_over(long n, long last_result)
{
	if (n / 10 != last_result)
		return (1);
	return (0);
}

static int	skip_spaces__check_sign(int sign, const char *str, int *i)
{
	while ((str[*i] && ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)))
	(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	long	last_result;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	sign = skip_spaces__check_sign(sign, str, &i);
	while (ft_isdigit(str[i]) == 1)
	{
		last_result = num;
		num = num * 10 + str[i] - 48;
		if ((check_over(num, last_result) == 1) && sign == -1)
			return (0);
		else if ((check_over(num, last_result) == 1) && sign == 1)
			return (-1);
		i++;
	}
	return (num * sign);
}
