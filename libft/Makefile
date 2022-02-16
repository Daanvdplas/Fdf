# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 08:21:01 by dvan-der          #+#    #+#              #
#    Updated: 2022/02/04 12:13:36 by dvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME := libft.a

CFLAGS := -Wall -Wextra -Werror

SRCS := \
ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_strdup.c \
ft_calloc.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_strmapi.c \
ft_striteri.c \
ft_nbrlen.c \
ft_atoi_binary_str.c \
get_next_line.c \
get_next_line_utils.c \
ft_puthexnbr_fd.c \
ft_free_split_str.c \
ft_check_malloc.c

BONUS_SRCS := \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstnew.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

OBJS := ${SRCS:%.c=%.o}

BONUS_OBJS := ${BONUS_SRCS:%.c=%.o}

HEADERFILES := \
libft.h \
get_next_line.h

ifdef WITH_BONUS
ALL_OBJS = $(OBJS) $(BONUS_OBJS)
else
ALL_OBJS = $(OBJS)
endif

all: $(NAME) 

%.o: %.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(ALL_OBJS)
	ar -ru $(NAME) $^

bonus:
	$(MAKE) WITH_BONUS=1

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $^

re:	fclean all

.PHONY: all, clean, fclean, re, bonus
