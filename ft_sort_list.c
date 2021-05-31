/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:09:29 by nboisde           #+#    #+#             */
/*   Updated: 2021/05/19 13:52:43 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_list(t_list **begin, int (*cmp)())
{
	t_list	*l1;
	void	*tmp;

	l1 = *begin;
	while (l1->next)
	{
		if (cmp(l1->next->content, l1->content) < 0)
		{
			tmp = l1->next->content;
			l1->next->content = l1->content;
			l1->content = tmp;
			l1 = *begin;
		}
		else
			l1 = l1->next;
	}
}
