/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azirari <azirari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:30:42 by azirari           #+#    #+#             */
/*   Updated: 2025/11/03 14:44:44 by azirari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(long n, int fd, int base, char xX);
int	ft_putstr_fd(char *s, int fd);
int	ft_put_unsigned(unsigned int i);
int	ft_put_add(void *ptr);

#endif
