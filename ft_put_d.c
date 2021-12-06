/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:47:31 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 10:40:44 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_d(va_list arg, t_spec *spec)
{
	int	c;
	int	ival;
	int	ilen;

	c = 0;
	ival = va_arg(arg, int);
	ilen = ft_intlen(ival);
	if (spec->precision == 0 && ival == 0)
		ilen = ilen - 1;
	if (spec->precision > -1 && spec->zero == 1)
		spec->zero = 0;
	if (spec->precision > ilen && spec->precision > -1)
		ilen = spec->precision;
	if (spec->plus != 0 || spec->space != 0 || ival < 0)
		ilen += 1;
	if (spec->width < ilen)
	{
		ft_sign(ival, spec);
		if (spec->precision > -1 && (spec->zero == 0 || spec->minus == 0))
			ft_fillpre(ival, spec);
		ft_putnbr(ival, spec);
	}
	else
		c += ft_d_big_w(ival, spec, ilen);
	return (c + ilen);
}

int	ft_d_big_w(int ival, t_spec *spec, int ilen)
{
	int	c;

	c = 0;
	if (spec->zero == 1 || spec->minus == 1)
		ft_sign (ival, spec);
	if (spec->precision > -1 && (spec->zero == 1 || spec->minus == 1))
		ft_fillpre (ival, spec);
	if (spec->minus == 1)
		ft_putnbr (ival, spec);
	while (c < spec->width - ilen)
	{
		if (spec->zero == 1 && spec->minus == 0)
			ft_putchar ('0');
		else
			ft_putchar (' ');
		c++;
	}
	if (spec->zero == 0 && spec->minus == 0)
		ft_sign (ival, spec);
	if (spec->precision > -1 && (spec->zero == 0 && spec->minus == 0))
		ft_fillpre (ival, spec);
	if (spec->minus == 0)
		ft_putnbr (ival, spec);
	return (c);
}
