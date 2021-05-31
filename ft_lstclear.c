/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:07:43 by nboisde           #+#    #+#             */
/*   Updated: 2021/04/06 09:58:10 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		elem = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		(*lst) = elem;
	}
	lst = NULL;
}
