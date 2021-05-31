/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:03:24 by nboisde           #+#    #+#             */
/*   Updated: 2021/05/19 13:55:53 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\r' || c == '\v' || c == '\f'
		|| c == '\n' || c == ' ')
		return (1);
	return (0);
}

static int	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long int	res;
	int				i;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_sign(str[i]) != 0)
	{
		sign *= ft_sign(str[i]);
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (sign * (int)res);
}

int	ft_atol(const char *str)
{
	long				i;
	unsigned long long	nb;
	long				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (*(str + i) == '\n' || *(str + i) == '\t'
		|| *(str + i) == '\r' || *(str + i) == '\v'
		|| *(str + i) == '\f' || *(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		nb = nb * 10 + (*(str + i++) - '0');
		if (sign == 1 && nb > LONG_MAX)
			return (0);
		else if (nb > LONG_MAX)
			return (0);
	}
	return (nb * sign);
}
