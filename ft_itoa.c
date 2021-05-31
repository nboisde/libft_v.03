/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:06:37 by nboisde           #+#    #+#             */
/*   Updated: 2021/05/19 13:54:48 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_itoa(char **itoa, int n, size_t len)
{
	long	n_long;

	n_long = (long)n;
	if (n < 0)
	{
		(*itoa)[0] = '-';
		n_long *= -1;
	}
	if (n_long > 9)
		fill_itoa(itoa, (int)(n_long / 10), len - 1);
	(*itoa)[len] = n_long % 10 + 48;
}

static size_t	itoa_len(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	len;

	len = itoa_len(n);
	itoa = (char *)malloc(len + 1);
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	len--;
	fill_itoa(&itoa, n, len);
	return (itoa);
}
