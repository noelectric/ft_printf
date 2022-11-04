/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:48:28 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/02 02:16:55 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_puthex(unsigned long n, int *count)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, count);
		ft_puthex(n % 16, count);
	}
	else if (n < 10)
		ft_putchar(n + 48, count);
	else
		ft_putchar (n + 87, count);
}

void	size_h(unsigned long n, int *i)
{
	if (n >= 16)
	{
		size_h(n / 16, i);
		size_h(n % 16, i);
	}
	else if (n < 10)
		(*i)++;
	else
		(*i)++;
}

int	ft_print_ptr(long n, t_printdi params)
{
	int	i;

	params.pointed = 0;
	i = 0;
	size_h(n, &i);
	if (params.precision < i)
		params.precision = i;
	params.width -= params.precision + 2;
	if (!(params.flag & MINESS) && !(params.flag & ZERO))
		while (params.width-- > 0)
			ft_putchar(32, &params.pointed);
	params.pointed += write(1, "0x", 2);
	if ((params.flag & ZERO))
		while (params.width-- > 0)
			ft_putchar(48, &params.pointed);
	while (i < params.precision--)
		ft_putchar(48, &params.pointed);
	ft_puthex(n, &params.pointed);
	while (params.width-- > 0)
		ft_putchar(32, &params.pointed);
	return (params.pointed);
}
