/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:23:21 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/08 15:21:20 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_upper_hexa(unsigned int nb)
{
	char	*hexa_num;
	int		count;

	count = 0;
	hexa_num = "0123456789ABCDEF";
	if (nb < 16)
		count += ft_print_char(hexa_num[nb]);
	if (nb >= 16)
	{
		count += ft_print_upper_hexa(nb / 16);
		count += ft_print_upper_hexa(nb % 16);
	}
	return (count);
}
