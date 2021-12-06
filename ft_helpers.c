/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:42:14 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 11:25:17 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_l(const char *s, int len)
{
	int	c;

	c = 0;
	while (s[c] != '\0' && c < len)
	{
		ft_putchar (s[c]);
		c++;
	}
	return (c);
}

void	ft_putunbr(unsigned int n, t_spec *spec)
{
	if (spec->precision == 0 && n == 0)
		return ;
	if (n >= 10)
		ft_putnbr ((n / 10), spec);
	ft_putchar (n % 10 + '0');
}

void	ft_putnbr(int n, t_spec *spec)
{
	if (spec->precision == 0 && n == 0)
		return ;
	if (n == -2147483648)
		write(1, "2147483648", 10);
	else
	{
		if (n < 0)
		{
			n = -n;
		}
		if (n >= 10)
			ft_putnbr ((n / 10), spec);
		ft_putchar (n % 10 + '0');
	}
}

int	ft_putbase(unsigned long n, const char *base, int c)
{
	unsigned long	blen;

	blen = ft_strlen (base);
	if (n == (unsigned long) -2147483648)
	{
		ft_putstr_l("80000000", 10);
		return (10);
	}
	if (n < blen)
		c += ft_putchar (base[n]);
	else
	{
		c += ft_putbase ((n / blen), base, c);
		c += ft_putchar (base[n % blen]);
	}
	return (c);
}
