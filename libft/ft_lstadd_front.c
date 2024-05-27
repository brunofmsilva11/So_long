/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:15:58 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/08 15:20:54 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new -> next = *lst;
		*lst = new;
	}
}

/*int	main(void)
{
	t_list *new,*lst1;
	new = ft_lstnew("fabio");
	lst1 = ft_lstnew("fabio");
	ft_lstadd_front(&lst1, new);
}*/