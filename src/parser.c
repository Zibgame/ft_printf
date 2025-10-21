/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:29:34 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/21 13:49:10 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putarg_int(char type, va_list args)
{
	if (type == 'd' || type == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (type == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
}

static void	ft_putarg_char(char type, va_list args)
{
	if (type == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	else if (type == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (type == '%')
		ft_putchar_fd('%', 1);
}

void	ft_putarg(char type, va_list args)
{
	if (type == 'd' || type == 'i' || type == 'u')
		ft_putarg_int(type, args);
	else if (type == 'c' || type == 's' || type == '%')
		ft_putarg_char(type, args);
	else if (type == 'x' || type == 'X')
		ft_putarg_hex(type, args);
	else if (type == 'p')
		ft_putptr(va_arg(args, void *));
}

void	parser(const char *str, va_list args)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i += write(1, "%", 1) + 1;
		else if (str[i] == '%' && str[i + 1])
		{
			i++;
			ft_putarg(str[i++], args);
		}
		else
			write(1, &str[i++], 1);
	}
}
