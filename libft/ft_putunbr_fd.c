/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:49:24 by zcadinot          #+#    #+#             */
/*   Updated: 2025/10/22 14:49:29 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	len++;
	return (len);
}
