/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:21:38 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/21 12:43:51 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	ft_printf("salut %d %% ya cmb de %c pourcent",10,'y');
	ft_printf("\n");
	printf("salut %d %% ya cmb de %c pourcent",10,'y');
	return (0);
}
