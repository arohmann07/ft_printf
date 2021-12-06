/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:09:47 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 13:07:38 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fillpre(int ival, t_spec *spec)
{
	int		i;
	int		len;

	len = ft_intlen(ival);
	i = 0;
	if (spec->precision == 0 && ival == 0)
		len = 0;
	if (spec->precision > -1)
	{	
		if (spec->space == 1 || spec->plus == 1)
			write(1, "0", 1);
		while (i < spec->precision - len)
		{
			write(1, "0", 1);
			i++;
		}
	}	
	return (len + i);
}

int	ft_fillpre_u(unsigned int ival, t_spec *spec)
{
	int		i;
	int		len;

	len = ft_ulen(ival);
	i = 0;
	if (spec->precision == 0 && ival == 0)
		len = 0;
	if (spec->precision > -1)
	{	
		if (spec->space == 1 || spec->plus == 1)
			write(1, "0", 1);
		while (i < spec->precision - len)
		{
			write(1, "0", 1);
			i++;
		}
	}	
	return (len + i);
}

int	ft_fillpre_x(unsigned int ival, t_spec *spec)
{
	int		i;
	int		len;

	len = ft_xlen(ival);
	i = 0;
	if (spec->precision == 0 && ival == 0)
		len = 0;
	if (spec->precision > -1)
	{	
		if (spec->space == 1 || spec->plus == 1)
			write(1, "0", 1);
		while (i < spec->precision - len)
		{
			write(1, "0", 1);
			i++;
		}
	}	
	return (len + i);
}

void	ft_sign(int val, t_spec *spec)
{
	if (val < 0)
		write(1, "-", 1);
	if (val >= 0 && spec->plus == 1)
		write(1, "+", 1);
	else if (val >= 0 && spec->space == 1)
		write(1, " ", 1);
}
