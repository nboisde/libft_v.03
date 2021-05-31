/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:56:50 by nboisde           #+#    #+#             */
/*   Updated: 2021/05/19 13:55:06 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_copy_list(t_list *list)
{
	t_list	*cpy;
	t_list	*tmp;

	cpy = ft_lstnew(ft_strdup(list->content));
	tmp = list->next;
	while (tmp)
	{
		ft_lstadd_back(&cpy, ft_lstnew(ft_strdup(tmp->content)));
		tmp = tmp->next;
	}
	return (cpy);
}
