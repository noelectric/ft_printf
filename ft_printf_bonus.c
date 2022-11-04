/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:51:18 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/03 11:01:22 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	v_print(char **format, va_list data, t_printdi params)
{
	int	pointed;

	pointed = 0;
	if (*(*format) == 'c')
	{
		(*format)++;
		pointed = ft_print_c(va_arg(data, int), params);
	}
	else if (*(*format) == 's')
	{
		(*format)++;
		pointed = ft_print_s(va_arg(data, char *), params);
	}
	else if (*(*format) == 'p')
	{
		(*format)++;
		pointed = ft_print_ptr((unsigned long)va_arg(data, void *), params);
	}
	else if (*(*format) == 'u')
	{
		(*format)++;
		pointed = ft_print_u(va_arg(data, unsigned int), params);
	}
	return (pointed);
}

int	s_print(char **format, va_list data, t_printdi params)
{
	if (*(*format) == 'd' || *(*format) == 'i')
	{
		(*format)++;
		params.pointed = ft_print_d_i(va_arg(data, int), params);
	}
	else if (*(*format) == 'x')
	{
		(*format)++;
		params.pointed = ft_print_x(va_arg(data, unsigned int), params);
	}
	else if (*(*format) == 'X')
	{
		(*format)++;
		params.pointed = ft_print_upx(va_arg(data, unsigned int), params);
	}
	return (params.pointed);
}

int	x_print(char **format, t_printdi params)
{
	int	index;

	index = 32;
	if (*(*format) == '%')
	{
		if (params.flag & ZERO && !(params.flag & MINESS))
			index = 48;
		if (!(params.flag & MINESS))
			while (params.width-- > 1)
				params.pointed += write(1, &index, 1);
		params.pointed = write(1, "%", 1);
		while (params.width-- > 1)
			params.pointed += write(1, &index, 1);
		(*format)++;
	}
	else
	{
		params.pointed = write(1, *format, 1);
		(*format)++;
	}
	return (params.pointed);
}

int	ft_print(char *format, va_list data, int pointed)
{
	t_printdi	params;

	params.flag = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format, &pointed);
			format++;
		}
		else
		{
			params.flag = ft_checkflag(&format);
			ft_checkwp(&format, &params.precision, &params.width);
			if (*format == 'c' || *format == 's' || *format == 'p'
				|| *format == 'u')
				pointed += v_print(&format, data, params);
			else if (*format == 'd' || *format == 'i' || *format == 'x'
				||*format == 'X')
				pointed += s_print(&format, data, params);
			else
				pointed += x_print(&format, params);
		}
	}
	return (pointed);
}

int	ft_printf(const char *format, ...)
{
	va_list	data;
	int		printed;

	va_start(data, format);
	printed = 0;
	printed = ft_print((char *)format, data, printed);
	va_end(data);
	return (printed);
}
