/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:21:38 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/21 13:35:07 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	ft_printf("salut %d %% ya cmb de %c pourcent %s %u %x %X",10,'y',"banane",12345,255,255);
	ft_printf("\n");
	printf("salut %d %% ya cmb de %c pourcent %s %u %x %X",10,'y',"banane",12345,255,255);
	return (0);
}
