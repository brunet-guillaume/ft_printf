# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 21:40:01 by gbrunet           #+#    #+#              #
#    Updated: 2023/11/12 16:30:20 by gbrunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

INCLUDES = includes

SRC_DIR = src/

OBJ_DIR = obj/

SRC_FILES = ft_printf options percent_parcer print_c print_s print_p print_d \
		print_u print_x helper

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY : all clean fclean re bonus tester

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

clean :
	$(RM) -rf $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re : fclean all

bonus : all

tester : all
	$(CC) $(FLAGS) $(NAME) tester.c -o tester && ./tester
