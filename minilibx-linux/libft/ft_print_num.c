/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:15:45 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/08 15:21:15 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_num(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i += ft_print_char ('-');
	}
	if (nb < 10)
		i += ft_print_char (nb + 48);
	else
	{
		i += ft_print_num (nb / 10);
		i += ft_print_num (nb % 10);
	}
	return (i);
}
