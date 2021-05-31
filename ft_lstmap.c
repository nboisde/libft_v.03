/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:09:24 by nboisde           #+#    #+#             */
/*   Updated: 2021/03/01 13:50:06 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*elem;

	if (!f || !lst)
		return (0);
	first = 0;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!(elem))
		{
			while (first)
			{
				elem = first->next;
				del(elem->content);
				free(elem);
				first = elem;
			}
		}
		ft_lstadd_back(&first, elem);
		lst = lst->next;
	}
	return (first);
}
