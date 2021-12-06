/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:54:20 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 11:26:24 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulen(unsigned int val)
{
	if (val < 10)
		return (1);
	return (ft_ulen(val / 10) + 1);
}

int	ft_xlen(unsigned int val)
{
	if (val < 16)
		return (1);
	return (ft_xlen(val / 16) + 1);
}

unsigned int	ft_intlen(int ival)
{
	if (ival == -2147483648)
		return (10);
	if (ival < 0)
	{
		ival = -ival;
	}
	if (ival < 10)
		return (1);
	return (ft_intlen(ival / 10) + 1);
}

unsigned int	ft_ptrlen(unsigned long pval)
{
	if (pval < 16)
		return (1);
	return (ft_ptrlen(pval / 16) + 1);
}
