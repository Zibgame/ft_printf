/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:34:59 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/21 11:20:27 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list args_list;
	va_start(args_list,s);
	if (!s)
		return (0);
	parser(s,args_list);
	return(ft_strlen(s));
}
