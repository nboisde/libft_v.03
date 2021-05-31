/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:13:03 by nboisde           #+#    #+#             */
/*   Updated: 2021/05/19 13:52:27 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s, int n)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i] && i < n)
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (0);
	i = 0;
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (!s[i + 1] || (s[i] == c && s[i + 1] != c)
			|| (s[i + 1] == c && !s[i + 1]))
			words++;
		i++;
	}
	if (words == 0)
		words++;
	return (words);
}

int	len_stop(char const *s, char c)
{
	int	i;

	i = 0;
	while (c != s[i] && s[i])
		i++;
	return (i);
}

void	*free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i++]);
	}
	if (tab)
		free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	while (j < count_words(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		split[j] = ft_strndup(&s[i], len_stop(&s[i], c));
		if (!split[j])
			return (free_tab(split));
		j++;
		i += len_stop(&s[i], c);
	}
	split[j] = 0;
	return (split);
}
