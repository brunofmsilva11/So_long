/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:08:08 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/08 15:21:01 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*lst: The beginning of the list.
Returns the last node of the list*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != NULL)
	{
		lst = lst ->next;
	}
	return (lst);
}
