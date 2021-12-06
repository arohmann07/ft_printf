/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:57:02 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 09:16:35 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		c;
	va_list	arg;

	va_start(arg, s);
	c = 0;
	c = ft_str_search(s, arg);
	va_end(arg);
	return (c);
}

int	ft_str_search(const char *s, va_list arg)
{
	int	i;
	int	c;
	int	*ptr;

	ptr = &i;
	i = 0;
	c = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			c += ft_putchar(s[i]);
			i++;
		}
		else if (s[i] == '%')
		{
			i++;
			c = ft_check_all(s, arg, c, ptr);
		}
		else
			i++;
	}
	return (c);
}

int	ft_check_all(const char *s, va_list arg, int c, int *ptr)
{
	t_spec	*spec;

	spec = ft_new_spec();
	*ptr = ft_set_flag(s, spec, *ptr);
	*ptr = ft_set_width(s, spec, *ptr);
	*ptr = ft_set_prec(s, spec, *ptr);
	*ptr = ft_set_type(s, spec, *ptr);
	c += ft_write_types(arg, spec);
	free(spec);
	return (c);
}

t_spec	*ft_new_spec(void)
{
	t_spec	*spec;

	spec = malloc(sizeof(t_spec));
	if (spec == NULL)
		return (NULL);
	spec->minus = 0;
	spec->hash = 0;
	spec->zero = 0;
	spec->plus = 0;
	spec->space = 0;
	spec->point = 0;
	spec->type = 0;
	spec->width = -1;
	spec->precision = -1;
	return (spec);
}
