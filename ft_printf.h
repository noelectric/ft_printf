/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:50:32 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/02 02:33:33 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include<stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c, int *count);
void	ft_putstr(const char *str, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putunbr(unsigned int n, int *count);
void	ft_puthex(unsigned long n, int *count);
void	ft_putheupx(unsigned long n, int *count);
void	ft_putpointer(void *p, int *count);
size_t	ft_strlen(const char *str);
#endif
