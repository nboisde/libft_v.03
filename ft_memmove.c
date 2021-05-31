/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:11:22 by nboisde           #+#    #+#             */
/*   Updated: 2020/11/10 17:19:14 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*mdst;
	unsigned char	*msrc;

	mdst = (unsigned char *)dst;
	msrc = (unsigned char *)src;
	i = 0;
	if (!src && !dst)
		return (dst);
	if (mdst > msrc)
		while (++i <= len)
			mdst[len - i] = msrc[len - i];
	else
		while (len-- > 0)
			*(mdst++) = *(msrc++);
	return (dst);
}
