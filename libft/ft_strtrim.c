/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:18:33 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/08 15:19:53 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string 
strtrim removes all whitespace characters from the 
beginning and the end of a string. In other words,
 it will remove all the unnecessary white
 that you might have in a string*/

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*result;
	int		start;
	int		end;

	start = 0;
	if (!str)
		return (0);
	end = ft_strlen((char *)str);
	while (str[start] && ft_strchr((char *)set, str[start]))
		start++;
	while (end > start && ft_strchr((char *)set, str[end - 1]))
		end--;
	result = ft_substr(str, start, (end - start));
	return (result);
}

/*#include <stdio.h>

int main()
{
    char a[] = "  aabcdefgg  ";
    char s[] = "ag ";
    char *str;
    str = ft_strtrim(a, s);
    printf("|%s|\n", str);
    return 0;
}*/