/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:01:08 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/02 02:16:58 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	ft_putstr(const char *str, int *count, int precision)
{
	int	i;

	if (!str)
		*count += write(1, "(null)", 6);
	else
	{
		i = 0;
		while (str[i] && precision-- > 0)
			ft_putchar(str[i++], count);
	}
}

int	ft_print_s(char *s, t_printdi params)
{
	int	len;
	int	pointed;

	pointed = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (params.precision == -1)
		params.precision = len;
	if (params.precision > len)
		params.precision = len;
	params.width -= params.precision;
	if ((params.flag & ZERO) && !(params.flag & MINESS))
		while (params.width-- > 0)
			pointed += write(1, "0", 1);
	if (!(params.flag & MINESS))
		while (params.width-- > 0)
			ft_putchar(32, &pointed);
	if (params.precision == -1)
		params.precision = len;
	ft_putstr(s, &pointed, params.precision);
	while (params.width-- > 0)
		ft_putchar(32, &pointed);
	return (pointed);
}
