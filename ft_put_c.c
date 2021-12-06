/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:46:27 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 09:39:57 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c(va_list arg, t_spec *spec)
{
	int				c;
	unsigned char	cval;

	c = 0;
	cval = (unsigned char)va_arg(arg, int);
	if (spec->width <= 1)
		write(1, &cval, 1);
	else
	{
		if (spec->minus == 1)
			write(1, &cval, 1);
		while (c < spec->width - 1)
		{
			write(1, " ", 1);
			c++;
		}
		if (spec->minus == 0)
			write(1, &cval, 1);
	}
	return (c + 1);
}
