/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:12:11 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/02 02:16:39 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_checkflag(char **format)
{
	int	flag;
	int	t;

	flag = 0;
	t = 1;
	while (t != 0)
	{
		++(*format);
		if (*(*format) == '+')
			flag |= PLUS;
		else if (*(*format) == '#')
			flag |= SHARP;
		else if (*(*format) == ' ')
			flag |= SPACE;
		else if (*(*format) == '-')
			flag |= MINESS;
		else if (*(*format) == '0')
			flag |= ZERO;
		else
			t = 0;
	}
	return (flag);
}
