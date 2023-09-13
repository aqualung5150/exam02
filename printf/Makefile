NAME		= libftprintf.a

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Werror -Wextra

SRCS		= ft_printf.c

OBJS		= ft_printf.o

all			=$(NAME)

%.o : %.c
		${CC} ${CFLAGS} -c -o $@ $<

$(NAME):	$(OBJS)
				ar crs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)
				$(RM) ft_printf.h.gch

re:			fclean $(NAME)

.PHONY:		all clean fclean re
