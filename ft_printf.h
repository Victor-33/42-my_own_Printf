/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-brit <vde-brit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:01:05 by vde-brit          #+#    #+#             */
/*   Updated: 2022/09/08 19:48:46 by vde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

unsigned long int	count_digit(unsigned long int nbr);

int					ft_putstr(char *s);
int					ft_putchar(char c);
int					ft_putnbr(int n);
int					ft_putunbr(unsigned int n);

int					treat_p(unsigned long p);
int					treat_x(unsigned long n, char c);

int					treat_flags(va_list num_args, const char *src, int i);
int					ft_printf(const char *src, ...);

#endif
