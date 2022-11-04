/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:23:27 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/02 02:16:49 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_c(char c, t_printdi print)
{
	int	pointed;

	pointed = 0;
	if ((print.flag & ZERO) && !(print.flag & MINESS))
		while (--print.width > 0)
			pointed += write(1, "0", 1);
	if (!(print.flag & MINESS))
		while (--print.width > 0)
			pointed += write(1, " ", 1);
	ft_putchar(c, &pointed);
	while (--print.width > 0)
		pointed += write(1, " ", 1);
	return (pointed);
}
