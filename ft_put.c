/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:14:20 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 15:14:23 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_per(t_spec *spec)
{
	int	c;

	c = 0;
	if (spec->width < 1)
		ft_putchar ('%');
	else
	{
		if (spec->minus == 1)
			ft_putchar ('%');
		while (c < spec->width - 1)
		{
			if (spec->zero == 1 && spec->minus == 0)
				ft_putchar ('0');
			else
				ft_putchar (' ');
			c++;
		}
		if (spec->minus == 0)
			ft_putchar ('%');
	}
	return (c + 1);
}
