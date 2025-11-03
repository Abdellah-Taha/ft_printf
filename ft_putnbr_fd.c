/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <azirari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:55:36 by azirari           #+#    #+#             */
/*   Updated: 2025/11/03 14:44:52 by azirari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_fd(long n, int fd, int base, char xX)
{
	unsigned long	nb;
	int				i;
	char			*base_rep;

	base_rep = "0123456789abcdef";
	if (xX == 'X')
		base_rep = "0123456789ABCDEF";
	i = 0;
	if (n < 0 && base == 10)
	{
		i++;
		n = -n;
		write(fd, "-", 1);
	}
	nb = n;
	if (nb >= (unsigned long)base)
	{
		i += ft_putnbr_fd(nb / base, fd, base, xX);
		i += ft_putchar_fd(base_rep[(nb % base)], fd);
	}
	else
		i += ft_putchar_fd(base_rep[(nb % base)], fd);
	return (i);
}
