/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:16:02 by nboisde           #+#    #+#             */
/*   Updated: 2020/12/24 13:54:06 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	ncat;

	i = ft_strlen(s1);
	ncat = 0;
	while (ncat < n && s2[ncat])
	{
		s1[i] = s2[ncat];
		i++;
		ncat++;
	}
	s1[i] = '\0';
	return (s1);
}
