/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:25:27 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/02 02:16:30 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_atoi(char **format)
{
	int	r;

	r = 0;
	while (*(*format) <= 57 && *(*format) >= 48)
	{
		r = r * 10 + (*(*format) - 48);
		(*format)++;
	}
	return (r);
}
