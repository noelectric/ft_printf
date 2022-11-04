/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimzaoua <yimzaoua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:50:32 by yimzaoua          #+#    #+#             */
/*   Updated: 2022/01/03 10:59:05 by yimzaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include<stdarg.h>

# define PLUS 1
# define SHARP 2
# define MINESS 4
# define ZERO 8
# define SPACE 16

typedef struct s_printdi
{
	char		index;
	char		sign;
	int			i;
	int			pointed;
	long int	num;
	int			precision;
	int			width;
	int			flag;
}	t_printdi;

typedef struct s_printdu
{
	char			index;
	char			sign;
	int				i;
	int				pointed;
	unsigned int	num;
	int				precision;
	int				width;
	int				flag;

}	t_printdu;

// * print functions * //

int		ft_printf(const char *format, ...);
int		ft_print_c(char c, t_printdi params);
int		ft_print_ptr(long n, t_printdi params);
int		ft_print_s(char *s, t_printdi params);
int		ft_print_d_i(long int num, t_printdi params);
int		ft_print_u(unsigned int num, t_printdi params);
int		ft_print_x(unsigned int num, t_printdi params);
int		ft_print_upx(unsigned int num, t_printdi params);

// * utils functions * //

int		ft_putchar(int c, int *count);
void	ft_checkwp(char **format, int *precision, int *width);
int		ft_checkflag(char **format);
int		ft_isdigit(int arg);
int		ft_atoi(char **format);
char	*ft_itoa(long int n);
#endif
