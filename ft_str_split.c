/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 03:08:46 by nboisde           #+#    #+#             */
/*   Updated: 2021/05/19 13:51:55 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hit_cs(char c, char *cs)
{
	int	i;

	i = 0;
	while (cs[i])
	{
		if (c == cs[i])
			return (1);
		i++;
	}
	return (0);
}

int	len_stop_cs(char *str, char *cs)
{
	int	i;

	i = 0;
	while (!hit_cs(str[i], cs) && str[i])
		i++;
	return (i);
}

static int	count_w(char *str, char *cs)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!str[i + 1] || (hit_cs(str[i], cs) && !hit_cs(str[i + 1], cs))
			|| ((hit_cs(str[i + 1], cs) && !str[i + 1])))
			words++;
		i++;
	}
	if (words == 0)
		return (1);
	return (words);
}

char	**ft_str_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * (count_w(str, charset) + 1));
	if (!split)
		return (0);
	while (j < count_w(str, charset))
	{
		while (hit_cs(str[i], charset) && str[i])
			i++;
		if (!str[i])
			break ;
		split[j] = ft_strndup(&str[i], len_stop_cs(&str[i], charset));
		if (!split[j])
			free(split);
		j++;
		i += len_stop_cs(&str[i], charset);
	}
	split[j] = 0;
	return (split);
}
