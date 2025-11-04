/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:45:07 by azirari           #+#    #+#             */
/*   Updated: 2025/11/04 19:45:12 by azirari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_puthex2(unsigned long n, char *f)
{
	long	x;
	int		z;

	z = 0;
	if (n >= 16)
		z += ft_puthex2(n / 16, f);
	x = (n % 16);
	z += write(1, &f[x], 1);
	return (z);
}

int	ft_put_add(void *ptr)
{
	unsigned long	p;
	int				z;

	if (ptr == NULL)
	{
		z = write(1, "(nil)", 5);
		return (z);
	}
	p = (unsigned long)ptr;
	write(1, "0x", 2);
	z = ft_puthex2(p, "0123456789abcdef");
	return (z + 2);
}
