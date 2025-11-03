NAME  = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_put_add.c ft_putchar_fd.c ft_put_unsigned.c ft_putnbr_fd.c ft_putstr_fd.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : clean