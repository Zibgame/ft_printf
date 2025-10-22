/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:21:38 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/22 12:28:09 by zcadinot         ###   ########.fr       */
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
	printf("printf : %c\n", '0');
	ft_printf("ft_printf : %c\n", '0');
	return (0);
}
