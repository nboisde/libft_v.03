NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR 			= ar rcs
RM			= rm -f
IFLAGS		= -include libft.h

SRCS 		= ft_bzero.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memcmp.c \
			ft_memchr.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_atoi.c \
			ft_strnstr.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strcmp.c \
			ft_reassign.c \
			get_next_line.c \
			ft_putstr.c \
			ft_str_split.c \
			ft_str_builder.c \
			free_int_tab.c \
			ft_sort_list.c \
			ft_copy_list.c \
			len_tab.c \
			ft_put_tab_fd.c

SRCS_PATH	= srcs/
INC_PATH	= includes
OBJS		= ${SRCS:.c=.o}
CLEAR		= \033[2K\c

all:		${NAME}

%.o:		%.c
			@echo "${CLEAR}"
			@echo "compiling $<\r\c"
			@${CC} ${CFLAGS} ${IFLAGS} -o $@ -c $<

${NAME}:	${OBJS}
			@echo "${CLEAR}"
			@echo "${NAME} Created..."
			@${AR} ${NAME} ${OBJS}

clean:
			@echo "clean executed"
			@${RM} ${OBJS}

fclean:		clean
			@echo "fclean executed"
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all re clean fclean
