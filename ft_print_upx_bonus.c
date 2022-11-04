/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 02:44:32 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/02 02:17:05 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	len_n(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_putheupx(unsigned long n, int *count)
{
	if (n >= 16)
	{
		ft_putheupx(n / 16, count);
		ft_putheupx(n % 16, count);
	}
	else if (n < 10)
		ft_putchar(n + 48, count);
	else
		ft_putchar (n + 55, count);
}

static void	ft_get_sign(t_printdu *print)
{
	print->pointed = 0;
	print->sign = 0;
	if ((print->flag & ZERO) && (print->precision < 0))
		print->index = 48;
	else
		print->index = 32;
}

static void	ft_print_d(t_printdu *print)
{
	int	x;

	x = print->precision;
	print->i = len_n(print->num);
	if (print->i > print->precision)
		print->precision = print->i;
	print->width -= print->precision;
	if (print->flag & SHARP)
		print->width -= 2;
	if ((print->flag & SHARP) && (x == -1) && (print->num != 0))
		print->pointed += write(1, "0X", 2);
	if (!(print->flag & MINESS))
		while (print->width-- > 0)
			ft_putchar(print->index, &print->pointed);
	if ((print->flag & SHARP) && (x >= 0) && (print->num != 0))
		print->pointed += write(1, "0X", 2);
	while (print->precision-- > print->i)
		ft_putchar('0', &print->pointed);
	ft_putheupx(print->num, &print->pointed);
	if (print->flag & (ZERO + MINESS))
		while (print->width-- > 0)
			ft_putchar(32, &print->pointed);
}

int	ft_print_upx(unsigned int num, t_printdi params)
{
	t_printdu	print;

	print.precision = params.precision;
	print.num = num;
	print.width = params.width;
	print.flag = params.flag;
	ft_get_sign(&print);
	print.i = 0;
	if (num == 0 && params.precision == 0)
	{
		while (params.width-- > 0)
			ft_putchar(32, &print.pointed);
		return (print.pointed);
	}
	ft_print_d(&print);
	return (print.pointed);
}
