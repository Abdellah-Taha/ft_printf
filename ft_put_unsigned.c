/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <azirari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:51:07 by azirari           #+#    #+#             */
/*   Updated: 2025/11/03 12:48:47 by azirari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_put_unsigned(unsigned int i)
{
	int	n;

	n = 0;
	if (i >= 10)
		n += ft_put_unsigned(i / 10);
	n++;
	ft_putchar_fd((i % 10) + '0', 1);
	return (n);
}
