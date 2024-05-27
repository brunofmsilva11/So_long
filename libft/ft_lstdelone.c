/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:37:38 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/08 15:20:59 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*lst: The node to free.
del: The address of the function used to delete
the content.
Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed.*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

/*void	ft_delete(void* content)
{
	free(content);
}
int	main(void)
{
	ft_lstdelone(lst, &ft_delete);
}*/