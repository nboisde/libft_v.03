/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:17:41 by nboisde           #+#    #+#             */
/*   Updated: 2020/12/24 14:46:15 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;
	size_t		k;

	k = 0;
	i = (size_t)start;
	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if ((size_t)start < ft_strlen(s))
	{
		while (s[i] && i < len + start)
		{
			sub[k] = s[i];
			i++;
			k++;
		}
	}
	sub[k] = '\0';
	return (sub);
}
