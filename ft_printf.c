/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-brit <vde-brit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:38:45 by vde-brit          #+#    #+#             */
/*   Updated: 2022/09/13 15:37:50 by vde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_flags(va_list num_args, const char *src, int i)
{
	int	ret;

	if (src[i] == 'i' || src[i] == 'd')
		return (ft_putnbr(va_arg(num_args, int)));
	else if (src[i] == 'c')
		return (ft_putchar(va_arg(num_args, int)));
	else if (src[i] == 's')
		return (ft_putstr(va_arg(num_args, char *)));
	else if (src[i] == 'p')
		return (treat_p(va_arg(num_args, unsigned long)));
	else if (src[i] == 'u')
		return (ft_putunbr(va_arg(num_args, unsigned int)));
	else if (src[i] == 'x' || src[i] == 'X')
		return (treat_x(va_arg(num_args, unsigned int), src[i]));
	else if (src[i] == '%')
		return (ft_putchar('%'));
	else
		ret = 0;
	return (ret);
}

int	ft_printf(const char *src, ...)
{
	int		i;
	int		result;
	va_list	num_args;

	va_start(num_args, src);
	i = 0;
	result = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '%')
		{
			i++;
			result = result + treat_flags(num_args, src, i);
		}
		else
		{
			ft_putchar(src[i]);
			result++;
		}
	i++;
	}
	va_end(num_args);
	return (result);
}
