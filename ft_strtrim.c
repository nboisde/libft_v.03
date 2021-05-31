/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:17:21 by nboisde           #+#    #+#             */
/*   Updated: 2021/05/19 13:49:54 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_size;
	char	*trim;

	if (!s1)
		return (NULL);
	if (!set || !set[0] || !ft_strlen(s1))
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s_size = ft_strlen(s1);
	if (s_size == 0)
		return (ft_strdup(s1));
	while (s_size && ft_strchr(set, s1[s_size]))
		s_size--;
	trim = ft_substr((char *)s1, 0, s_size + 1);
	return (trim);
}
