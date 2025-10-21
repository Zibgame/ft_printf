/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:21:38 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/21 13:50:52 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	unsigned int	a;
	unsigned int	b;
	void			*ptr;

	a = 255;
	b = 3735928559;
	ptr = &a;
	printf("=== TEST %%x (hex minuscule) ===\n");
	printf("printf : %x\n", a);
	ft_printf("ft_printf : %x\n\n", a);
	printf("printf : %x\n", b);
	ft_printf("ft_printf : %x\n\n", b);
	printf("=== TEST %%X (hex majuscule) ===\n");
	printf("printf : %X\n", a);
	ft_printf("ft_printf : %X\n\n", a);
	printf("printf : %X\n", b);
	ft_printf("ft_printf : %X\n\n", b);
	printf("=== TEST %%p (pointeur) ===\n");
	printf("printf : %p\n", ptr);
	ft_printf("ft_printf : %p\n\n", ptr);
	printf("=== TEST MIXT %%d / %%u / %%x / %%X / %%p ===\n");
	printf("printf : d=%d, u=%u, x=%x, X=%X, p=%p\n", -42, 42, 42, 42, ptr);
	ft_printf("ft_printf : d=%d, u=%u, x=%x, X=%X, p=%p\n", -42, 42, 42, 42, ptr);
	return (0);
}
