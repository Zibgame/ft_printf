/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:29:34 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/21 12:52:24 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putarg(char type, va_list args)
{
	if (type == '%')
		ft_putchar_fd('%', 1);
	else if (type == 'd' || type == 'i')
	{
		int	d;

		d = va_arg(args, int);
		ft_putnbr_fd(d, 1);
	}
	else if (type == 'c')
	{
		char	c;

		c = (char)va_arg(args, int);
		ft_putchar_fd(c, 1);
	}
	else if (type == 's')
	{
		char *s;

		s = va_arg(args, char*);
		ft_putstr_fd(s,1);
	}
}

void	parser(const char *str, va_list args)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1])
		{
			i++;
			ft_putarg(str[i], args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}
