/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:16:17 by nboisde           #+#    #+#             */
/*   Updated: 2021/02/23 15:42:30 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < (n - 1) && s1[i] && s2[i] && (s1[i] == s2[i]))
			i++;
		if (s1[i] == s2[i])
			return (0);
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
	}
	return (0);
}
