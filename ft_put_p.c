/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:51:17 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 11:34:34 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p(va_list arg, t_spec *spec)
{
	int				c;
	int				plen;
	unsigned long	pval;

	c = 0;
	pval = (unsigned long)va_arg(arg, void *);
	plen = ft_ptrlen((unsigned long)pval) + 2;
	if (spec->width <= plen)
	{
		ft_putstr_l ("0x", 2);
		ft_putbase (pval, "0123456789abcdef", 0);
	}
	else
		c += ft_p_big_w (pval, spec, plen);
	return (plen + c);
}

int	ft_p_big_w(unsigned long pval, t_spec *spec, int plen)
{
	int	c;

	c = 0;
	if (spec->minus == 1)
	{
		ft_putstr_l ("0x", 2);
		ft_putbase (pval, "0123456789abcdef", 0);
	}
	while (c < spec->width - plen)
	{
		write(1, " ", 1);
		c++;
	}
	if (spec->minus == 0)
	{
		ft_putstr_l ("0x", 2);
		ft_putbase (pval, "0123456789abcdef", 0);
	}
	return (c);
}
