/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:48:54 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 13:02:47 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x(va_list arg, t_spec *spec)
{
	int				c;
	unsigned int	xval;
	int				xlen;

	c = 0;
	xval = va_arg(arg, unsigned int);
	xlen = ft_xlen(xval);
	xlen += ft_x_hash(xval, spec);
	if (spec->precision > -1 && spec->zero == 1)
		spec->zero = 0;
	if (spec->precision > xlen && spec->precision > -1)
		xlen = spec->precision;
	if (spec->width < xlen)
	{	
		if (spec->precision > 0 && spec->zero == 0)
			ft_fillpre_x (xval, spec);
		ft_x_choose (xval, spec);
	}
	else
		c += ft_x_big_w (xval, spec, xlen);
	return (xlen + c);
}

int	ft_x_big_w(unsigned int xval, t_spec *spec, int xlen)
{
	int	c;

	c = 0;
	if (spec->minus == 1)
	{
		if (spec->precision > 0)
			ft_fillpre_x (xval, spec);
		ft_x_choose (xval, spec);
	}
	while (c < spec->width - xlen)
	{
		if (spec->zero == 1 && spec->minus == 0)
			ft_putchar('0');
		else
			ft_putchar (' ');
		c++;
	}
	if (spec->minus == 0)
	{
		if (spec->precision > 0 && spec->zero == 0)
			ft_fillpre_x (xval, spec);
		ft_x_choose (xval, spec);
	}
	return (c);
}

int	ft_x_hash(unsigned int val, t_spec *spec)
{
	int	c;

	c = 0;
	if (spec->hash == 1 && spec->type == 'x' && val > 0)
	{
		ft_putstr_l("0x", 2);
		c = 2;
	}
	if (spec->hash == 1 && spec->type == 'X' && val > 0)
	{
		ft_putstr_l("0X", 2);
		c = 2;
	}
	return (c);
}

void	ft_x_choose(unsigned int xval, t_spec *spec)
{
	if (spec->precision == 0 && xval == 0 && spec->width == -1)
		return ;
	if (spec->precision == 0)
		ft_putchar(' ');
	else
	{
		if (spec->type == 'x')
			ft_putbase(xval, "0123456789abcdef", 0);
		if (spec->type == 'X')
			ft_putbase(xval, "0123456789ABCDEF", 0);
	}
}
