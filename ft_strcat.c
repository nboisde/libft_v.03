/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:13:19 by nboisde           #+#    #+#             */
/*   Updated: 2020/12/24 13:49:28 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	cat;

	i = ft_strlen((const char *)s1);
	cat = 0;
	while (cat < ft_strlen(s2))
	{
		s1[i] = s2[cat];
		i++;
		cat++;
	}
	s1[i] = '\0';
	return (s1);
}
