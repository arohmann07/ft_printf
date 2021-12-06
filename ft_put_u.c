/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:50:12 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 11:36:01 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(va_list arg, t_spec *spec)
{
	int				c;
	int				ulen;
	unsigned int	uval;

	c = 0;
	uval = va_arg(arg, unsigned int);
	ulen = ft_ulen(uval);
	if (spec->precision == 0 && uval == 0)
		ulen = ulen - 1;
	if (spec->precision > -1 && spec->zero == 1)
		spec->zero = 0;
	if (spec->precision > ulen && spec->precision > -1)
		ulen = spec->precision;
	if (spec->width < ulen)
	{
		ft_fillpre_u (uval, spec);
		ft_putunbr (uval, spec);
	}
	else
		c += ft_u_big_w(uval, spec, ulen);
	return (ulen + c);
}

int	ft_u_big_w(unsigned int uval, t_spec *spec, int ulen)
{
	int	c;

	c = 0;
	if (spec->minus == 1)
	{
		ft_fillpre_u (uval, spec);
		ft_putunbr (uval, spec);
	}
	while (c < spec->width - ulen)
	{
		if (spec->zero == 1 && spec->minus == 0)
			ft_putchar ('0');
		else
			ft_putchar (' ');
		c++;
	}
	if (spec->minus == 0)
	{
		ft_fillpre_u (uval, spec);
		ft_putunbr (uval, spec);
	}
	return (c);
}
