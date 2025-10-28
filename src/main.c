/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:04:22 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/28 12:04:24 by zcadinot         ###   ########.fr       */
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
	printf(NULL);
	ft_printf(NULL);
	return (0);
}
