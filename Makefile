NAME	= libftprintf.a
CC		= @gcc
Cflags	= -Wextra -Wall -Werror
RM		= rm -f
MOND	=	ft_puthex.c ft_putnbr.c ft_putstr.c ft_strlen.c \
			ft_printf.c ft_putchar.c ft_putheupx.c ft_putpointer.c ft_putunbr.c
BON		=	ft_checkwp_bonus.c ft_print_d_i_bonus.c ft_print_u_bonus.c\
			ft_printf_bonus.c ft_putchar_bonus.c ft_print_x_bonus.c ft_print_ptr_bonus.c ft_print_upx_bonus.c \
			ft_atoi_bonus.c ft_isdigit_bonus.c ft_print_s_bonus.c ft_print_c_bonus.c ft_checkflag_bonus.c \



O_MON	= $(MOND:.c=.o)

O_BON	= $(BON:.c=.o)

all		: $(NAME)

$(NAME)	: $(O_MON) ft_printf.h
		@ar rcs $(NAME) $(O_MON)
		@echo "\x1B[32m=============================================================\x1B[0m"
		@echo "\x1B[32m                        MAKE MONDATORY                       \x1B[0m"
		@echo "\x1B[32m=============================================================\x1B[0m"
		@echo "\x1B[32m                           DONE                              \x1B[0m"
		@echo "\x1B[32m=============================================================\x1B[0m"
clean	:
		@$(RM) $(O_MON) $(O_BON)
fclean	: clean
		@$(RM) $(NAME)
re		: fclean $(NAME)

bonus : $(O_BON) $(O_MON) ft_printf_bonus.h
	@rm -f $(NAME)
	@ar rcs $(NAME) $(O_BON) $(O_MON)
	@echo "\x1B[32m=============================================================\x1B[0m"
	@echo "\x1B[32m                        MAKE BONUS                           \x1B[0m"
	@echo "\x1B[32m=============================================================\x1B[0m"
	@echo "\x1B[32m                           DONE                              \x1B[0m"
	@echo "\x1B[32m=============================================================\x1B[0m"

norm :
	@norminette *.c *.h

.PHONY : clean fclean all re
