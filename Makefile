# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaprono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 11:41:27 by psaprono          #+#    #+#              #
#    Updated: 2018/07/19 16:12:42 by psaprono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := 	libftprintf.a

SRC :=		ft_printf.c ft_itoa_base.c ft_atoi_base.c

OBJ =		$(SRC:.c=.o)

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	libft/
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR)

CC_FLAGS :=		

LINK_FLAGS :=	$(LIBFT_FLAGS)

HEADER_FLAGS :=	-I. -I $(LIBFT_DIR)

CC :=			gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ -c $< $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
