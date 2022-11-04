/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:25:04 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/02 02:16:43 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_checkwp(char **format, int *precision, int *width)
{
	*width = 0;
	*precision = -1;
	if (ft_isdigit(*(*format)))
		*width = ft_atoi(format);
	if (*(*format) == '.')
	{
		(*format)++;
		*precision = 0;
		if (ft_isdigit(*(*format)))
			*precision = ft_atoi(format);
	}
}
