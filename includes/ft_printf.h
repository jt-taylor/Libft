/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:50:25 by jtaylor           #+#    #+#             */
/*   Updated: 2019/02/13 17:04:13 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

# define H	1
# define HH 2
# define L	3
# define LL	4
# define J	5
# define Z	6

typedef struct	s_struct
{
	int			i;
	int			len;
	int			fd;

	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;

	int			width;
	int			precision_specified;
	int			precision;
	int			length;
}				t_struct;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
void			ft_process_string(const char *format, t_struct *f, va_list ap);
void			ft_parse_modifiers(const char *format, t_struct *f, va_list ap);
void			ft_print_decimal(char type, t_struct *f, va_list ap);
void			ft_padding_left_align(int nbrlen, t_struct *f);
void			ft_padding_right_align(int nbrlen, int n, t_struct *f);
void			ft_print_unsigned_decimal(char type, t_struct *f, va_list ap);
void			ft_print_octal(char type, t_struct *f, va_list ap);
void			ft_print_hex(char type, t_struct *f, va_list ap);
void			ft_print_pointer(char type, t_struct *f, va_list ap);
void			ft_print_binary(char type, t_struct *f, va_list ap);
void			ft_print_char(char type, t_struct *f, va_list ap);
void			ft_print_string(char type, t_struct *f, va_list ap);
void			ft_print_percent_sign(char type, t_struct *f);
void			ft_print_float(char type, t_struct *f, va_list ap);

int				ft_itoa_base_pf(int fd, intmax_t value, int base);
int				ft_uitoa_base_pf(int fd, uintmax_t value, int base, char x);
int				ft_signed_nbr_len(intmax_t value, int base);
int				ft_unsigned_nbr_len(uintmax_t value, int base);
char			*ft_ldtoa(double n, int	precision);
#endif
