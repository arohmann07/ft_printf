/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:37:55 by arohmann          #+#    #+#             */
/*   Updated: 2021/07/23 11:35:02 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_spec
{
	char	minus;
	char	hash;
	char	zero;
	char	plus;
	char	space;
	char	point;
	char	type;
	int		width;
	int		precision;
}	t_spec;

int				ft_printf(const char *s, ...);
int				ft_str_search(const char *s, va_list arg);
int				ft_check_all(const char *s, va_list arg, int c, int *ptr);
int				ft_write_types(va_list arg, t_spec *spec);
int				ft_set_flag(const char *s, t_spec *spec, int i);
int				ft_set_type(const char *s, t_spec *spec, int i);
int				ft_set_prec(const char *s, t_spec *spec, int i);
int				ft_set_width(const char *s, t_spec *spec, int i);
int				ft_put_c(va_list arg, t_spec *spec);
int				ft_put_s(va_list arg, t_spec *spec);
int				ft_put_p(va_list arg, t_spec *spec);
int				ft_put_d(va_list arg, t_spec *spec);
int				ft_put_u(va_list arg, t_spec *spec);
int				ft_put_x(va_list arg, t_spec *spec);
int				ft_put_per(t_spec *spec);
int				ft_putbase(unsigned long n, const char *base, int c);
void			ft_putnbr(int n, t_spec *spec);
void			ft_putunbr(unsigned int n, t_spec *spec);
int				ft_putstr_l(const char *s, int len);
int				ft_fillpre(int ival, t_spec *spec);
int				ft_fillpre_u(unsigned int ival, t_spec *spec);
int				ft_fillpre_x(unsigned int ival, t_spec *spec);
void			ft_sign(int val, t_spec *spec);
unsigned int	ft_ptrlen(unsigned long pval);
unsigned int	ft_intlen(int ival);
int				ft_ulen(unsigned int val);
int				ft_xlen(unsigned int val);
t_spec			*ft_new_spec(void);
int				ft_d_big_w(int ival, t_spec *spec, int ilen);
int				ft_u_big_w(unsigned int uval, t_spec *spec, int ulen);
int				ft_x_big_w(unsigned int xval, t_spec *spec, int xlen);
int				ft_p_big_w(unsigned long pval, t_spec *spec, int plen);
int				ft_s_big_w(char *sval, t_spec *spec, int slen);
void			ft_x_choose(unsigned int xval, t_spec *spec);
int				ft_x_hash(unsigned int val, t_spec *spec);
int				ft_putchar(int c);

#endif