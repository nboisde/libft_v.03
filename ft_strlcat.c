/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:14:47 by nboisde           #+#    #+#             */
/*   Updated: 2021/05/19 13:50:46 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *src, size_t size)
{
	size_t	leno;

	leno = 0;
	while (src[leno] != '\0' && leno < size)
		leno++;
	return (leno);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lcat;

	lcat = ft_strnlen(dst, size);
	i = lcat;
	j = 0;
	if (size != 0)
	{
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	if (i < size)
		dst[i] = '\0';
	return (lcat + ft_strlen(src));
}
