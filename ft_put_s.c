/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:44:25 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 09:52:24 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_s(va_list arg, t_spec *spec)
{
	int		c;
	int		slen;
	char	*sval;

	c = 0;
	sval = va_arg(arg, char *);
	if (sval == NULL)
		sval = "(null)";
	slen = (int)ft_strlen(sval);
	if (spec->precision < slen && spec->precision > -1)
		slen = spec->precision;
	if (spec->width <= slen)
		ft_putstr_l (sval, slen);
	else
		c += ft_s_big_w(sval, spec, slen);
	return (c + slen);
}

int	ft_s_big_w(char *sval, t_spec *spec, int slen)
{
	int	c;

	c = 0;
	if (spec->minus == 1)
		ft_putstr_l (sval, slen);
	while (c < spec->width - slen)
	{
		write(1, " ", 1);
		c++;
	}
	if (spec->minus == 0)
		ft_putstr_l (sval, slen);
	return (c);
}
