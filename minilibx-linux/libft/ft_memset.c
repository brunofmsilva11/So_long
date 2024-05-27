/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:47:44 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/08 15:21:12 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memset() function fills the first n bytes of the memory area
       pointed to by s with the constant byte c.
*/

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}

/*int main () {
   char str[] = "This is string.h library function";

   ft_memset(str,'$',7);

   printf("%s\n", str);
   return(0);
}*/