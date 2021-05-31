/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:03:40 by nboisde           #+#    #+#             */
/*   Updated: 2021/05/19 13:49:36 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_buff(int fd, char **str)
{
	int		ret;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (*str == NULL)
			*str = ft_strdup(buf);
		else
			*str = ft_reassign(*str, buf, &ft_strjoin);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (ret);
}

int	get_line(int ret, char **str, char **line)
{
	char	*tmp;

	tmp = *str;
	if (ret == 0 && !*str)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (!ft_strchr(*str, '\n'))
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
	*line = ft_substr(tmp, 0, ft_strlen(tmp)
			- ft_strlen(ft_strchr(tmp, '\n')));
	*str = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char		*str[FD_MAX];
	char			buf;
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0
		|| read(fd, &buf, 0) == -1)
		return (-1);
	ret = read_buff(fd, &str[fd]);
	if (ret == -1)
		return (-1);
	return (get_line(ret, &str[fd], line));
}
