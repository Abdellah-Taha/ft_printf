/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <azirari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:23:06 by azirari           #+#    #+#             */
/*   Updated: 2025/11/03 17:15:56 by azirari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 's')
		count = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'u')
		count = ft_put_unsigned(va_arg(args, unsigned int));
	else if (c == 'c')
		count = ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 'i' || c == 'd')
		count = ft_putnbr_fd(va_arg(args, int), 1, 10, 'x');
	else if (c == 'x')
		count = ft_putnbr_fd(va_arg(args, unsigned int), 1, 16, 'x');
	else if (c == 'X')
		count = ft_putnbr_fd(va_arg(args, unsigned int), 1, 16, 'X');
	else if (c == 'p')
		count = ft_put_add(va_arg(args, void *));
	else if (c == '%')
		count = ft_putchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && *(++str) != '\0')
		{
			count += check(args, *str);
			str++;
		}
		if (*str == '\0')
			return (count);
		else
			count += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
