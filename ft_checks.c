/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:27:50 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 13:07:22 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_set_flag(const char *s, t_spec *spec, int i)
{
	while (ft_strchr("-#+0 ", s[i]) != 0 && s[i] != '\0')
	{
		if (s[i] == '-')
			spec->minus = 1;
		if (s[i] == '#')
			spec->hash = 1;
		if (s[i] == '+')
			spec->plus = 1;
		if (s[i] == '0')
			spec->zero = 1;
		if (s[i] == ' ')
			spec->space = 1;
		i++;
	}
	return (i);
}

int	ft_set_type(const char *s, t_spec *spec, int i)
{
	if (s[i] == 'c')
		spec->type = 'c';
	else if (s[i] == 's')
		spec->type = 's';
	else if (s[i] == 'p')
		spec->type = 'p';
	else if (s[i] == 'd')
		spec->type = 'd';
	else if (s[i] == 'i')
		spec->type = 'i';
	else if (s[i] == 'u')
		spec->type = 'u';
	else if (s[i] == 'x')
		spec->type = 'x';
	else if (s[i] == 'X')
		spec->type = 'X';
	else if (s[i] == '%')
		spec->type = '%';
	else
		return (i);
	return (i + 1);
}

int	ft_set_prec(const char *s, t_spec *spec, int i)
{
	int	value;

	value = 0;
	if (s[i] == '.')
	{
		i++;
		while (ft_isdigit(s[i]))
		{
			value = value * 10 + (s[i] - '0');
			i++;
		}
		spec->precision = value;
	}
	return (i);
}

int	ft_set_width(const char *s, t_spec *spec, int i)
{
	int	value;

	value = 0;
	if (ft_isdigit(s[i]))
	{	
		while (ft_isdigit(s[i]))
		{
			value = value * 10 + (s[i] - '0');
			i++;
		}
		spec->width = value;
	}
	return (i);
}

int	ft_write_types(va_list arg, t_spec *spec)
{
	int	c;

	c = 0;
	if (spec->type == 'c')
		c = ft_put_c(arg, spec);
	else if (spec->type == 's')
		c = ft_put_s(arg, spec);
	else if ((spec->type == 'd') || (spec->type == 'i'))
		c = ft_put_d(arg, spec);
	else if (spec->type == 'p')
		c = ft_put_p(arg, spec);
	else if (spec->type == 'u')
		c = ft_put_u(arg, spec);
	else if ((spec->type == 'x') || (spec->type == 'X'))
		c = ft_put_x(arg, spec);
	else if (spec->type == '%')
		c = ft_put_per(spec);
	return (c);
}
