/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-brit <vde-brit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:28:42 by vde-brit          #+#    #+#             */
/*   Updated: 2022/09/08 19:03:02 by vde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nb_base(size_t n, int base)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	treat_x(unsigned long n, char c)
{
	int	i;

	i = ft_nb_base(n, 16);
	if (n >= 16)
	{
		treat_x(n / 16, c);
		treat_x(n % 16, c);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + 48);
		else if (c == 'x')
			ft_putchar(n + 87);
		else
			ft_putchar(n + 55);
	}
	return (i);
}

static int	count_ptr(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

int	treat_p(unsigned long p)
{
	int	ret;

	ret = 0;
	if (p == 0)
		ret = (ft_putstr("(nil)"));
	else
	{
		ret = write(1, "0x", 2);
		ft_put_ptr(p);
		ret = ret + count_ptr(p);
	}
	return (ret);
}
