/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:52:50 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/08 15:21:03 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*void printlist (t_list *head)
{
  while (head != NULL)
  {
    printf("%s - ", head -> content);
    head = head ->next;
  }
  printf("\n");
}

int    main()
{
    char    str[] = "Rafael";
    char    str2[] = "23";
    t_list    *elem, *elem2;
    t_list *head;

    
    elem = ft_lstnew((void *)str);
    
    elem2 = ft_lstnew((void *)str2);
        
    head = elem;
    elem -> next = elem2;
    elem2 -> next = NULL;
    
    
    printlist(head);
    return 0;
}*/