/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reassign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:57:30 by nboisde           #+#    #+#             */
/*   Updated: 2021/04/06 11:14:32 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function takes a pointer on function and reassing and a char*
** and reassign the value, freeing the old value of the pointer
*/

char	*ft_reassign(char *s1, char *s2, char *(*f)(const char*, const char*))
{
	char	*tmp;

	tmp = s1;
	s1 = (*f)(s1, s2);
	free(tmp);
	return (s1);
}
