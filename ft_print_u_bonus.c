/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:24:38 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/02 02:17:01 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	len_n(long int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_putunbr(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putunbr((n / 10), count);
		ft_putunbr((n % 10), count);
	}
	else
		ft_putchar((n + 48), count);
}

static void	ft_get_sign(t_printdu *print)
{
	print->pointed = 0;
	print->sign = 0;
	if ((print->flag & ZERO) && (print->precision < 0))
		print->index = 48;
	else
		print->index = 32;
	if (print->flag & PLUS)
	{
		print->sign = '+';
		print->width--;
	}
	else if (print->flag & SPACE)
	{
		print->sign = ' ';
		print->width--;
	}
}

static void	ft_print_d(t_printdu *print)
{
	print->i = len_n(print->num);
	if (print->i > print->precision)
		print->precision = print->i;
	print->width -= print->precision;
	if (print->sign && print->index == '0')
		ft_putchar(print->sign, &print->pointed);
	if (!(print->flag & MINESS))
		while (print->width-- > 0)
			ft_putchar(print->index, &print->pointed);
	if (print->sign && print->index != '0')
		ft_putchar(print->sign, &print->pointed);
	while (print->precision-- > print->i)
		ft_putchar('0', &print->pointed);
	ft_putunbr(print->num, &print->pointed);
	if (print->flag & (ZERO + MINESS))
		while (print->width-- > 0)
			ft_putchar(32, &print->pointed);
}

int	ft_print_u(unsigned int num, t_printdi params)
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
		while ((params.width)-- > 0)
			ft_putchar(32, &print.pointed);
		return (print.pointed);
	}
	ft_print_d(&print);
	return (print.pointed);
}
