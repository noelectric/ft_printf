/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:50:40 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/02 02:36:54 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(va_list data, const char *format, int *count, int *i)
{
	if (format[*i] == '%')
		ft_putchar(format[*i], count);
	else if (format[*i] == 'c')
		ft_putchar(va_arg(data, int), count);
	else if (format[*i] == 's')
		ft_putstr(va_arg(data, char *), count);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_putnbr(va_arg(data, int), count);
	else if (format[*i] == 'u')
		ft_putunbr(va_arg(data, unsigned int), count);
	else if (format[*i] == 'x')
		ft_puthex(va_arg(data, unsigned int), count);
	else if (format[*i] == 'X')
		ft_putheupx(va_arg(data, unsigned int), count);
	else if (format[*i] == 'p')
		ft_putpointer(va_arg(data, void *), count);
	*i = *i + 1;
}

int	ft_printf(const char *format, ...)
{
	va_list	data;
	int		i;
	int		count;

	va_start(data, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i++], &count);
		else
		{
			i++;
			ft_print(data, format, &count, &i);
		}
	}
	va_end (data);
	return (count);
}
