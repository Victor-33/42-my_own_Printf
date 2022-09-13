/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-brit <vde-brit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:28:19 by vde-brit          #+#    #+#             */
/*   Updated: 2022/09/06 20:28:20 by vde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

unsigned long int	count_digit(unsigned long int nbr)
{
	unsigned long int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		++count;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
		ft_putnbr(n);
		return (count_digit(n) + 1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		return (count_digit(n));
	}
	else
	{
		ft_putchar(n + '0');
	}
	return (1);
}

int	ft_putunbr(unsigned int n)
{
	unsigned int	aux;

	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
		return (1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		return (count_digit(n));
	}
	else if (n < 0)
	{
		n = n * (-1);
		ft_putnbr(n);
	}
	return (0);
}
