/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:42:23 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/21 13:56:34 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_recursive(unsigned int n, char *base)
{
	if (n >= 16)
		ft_puthex_recursive(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}

void	ft_putarg_hex(char type, va_list args)
{
	unsigned int	n;
	char			*base;

	n = va_arg(args, unsigned int);
	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_puthex_recursive(n, base);
}

void	ft_putptr_recursive(unsigned long n)
{
	if (n >= 16)
		ft_putptr_recursive(n / 16);
	ft_putchar_fd("0123456789abcdef"[n % 16], 1);
}

void	ft_putptr(void *ptr)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	if (addr == 0)
		ft_putchar_fd('0', 1);
	else
		ft_putptr_recursive(addr);
}
