# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 21:40:01 by gbrunet           #+#    #+#              #
#    Updated: 2024/03/20 11:02:30 by gbrunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_BLACK = \033[0;30m
_RED = \033[0;31m
_GREEN = \033[0;32m
_BLUE = \033[0;34m
_YELLOW = \033[0;33m
_PURPLE = \033[0;35m
_CYAN = \033[0;36m
_WHITE = \033[0;37m

_BOLD = \e[1m
_THIN = \e[2m

_END = \033[0m

NAME = libftprintf.a

CC = cc

LIBFT = libft

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES) -I $(LIBFT)/includes

SRC_DIR = src/

OBJ_DIR = obj/

SRC_FILES = ft_printf options percent_parcer print_c print_s print_p print_d \
		print_u print_x print_x_helper helper print_d_helper print_u_helper

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

COMPTEUR = 0

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(eval COMPTEUR=$(shell echo $$(($(COMPTEUR)+1))))
	@printf "\e[?25l"
	@mkdir -p $(OBJ_DIR)
	@if test $(COMPTEUR) -eq 1;then \
		printf "$(_YELLOW)Compiling $(NAME) binary files...$(_END)\n\n";fi
	@printf "\033[A\33[2K\r$(_CYAN)Binary $(COMPTEUR): $@$(_END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re bonus tester norme

all : $(NAME)

$(NAME) : $(OBJ)
	@make info --no-print-directory
	@make -C $(LIBFT) --no-print-directory
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(_GREEN)$(NAME) created$(_END)"
	@printf "\e[?25h"

clean :
	@echo "$(_YELLOW)$(NAME): Clean...$(_END)"
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(_GREEN)$(NAME): Binaries deleted...$(_END)"
	@make clean -C $(LIBFT) --no-print-directory

fclean :
	@echo "$(_YELLOW)$(NAME): Full clean...$(_END)"
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(_GREEN)$(NAME): Binaries deleted...$(_END)"
	@$(RM) $(NAME)
	@echo "$(_GREEN)$(NAME) deleted...$(_END)"
	@make fclean -C $(LIBFT) --no-print-directory

re : 
	@make fclean --no-print-directory
	@make all --no-print-directory
	@printf "\e[?25h"

norme :
	@norminette $(SRC) $(LIBFT) | grep -v Norme -B1 || true
	@norminette $(INCLUDES) -R CheckDefine | grep -v Norme -B1 || true

info :
	@printf "\t$(_PURPLE)╭──────────────────────────────────────╮"
	@printf "\n\t│$(_END)  👾  $(_CYAN)$(_THIN)Coded by $(_END)$(_CYAN)"
	@printf "$(_BOLD)guillaume brunet$(_END)$(_PURPLE)       │\n"
	@printf "\t│$(_END)  💬  $(_RED)$(_BOLD)Do not copy$(_END)$(_RED)$(_THIN), "
	@printf "$(_END)$(_RED)this is useless...$(_END) $(_PURPLE)│\n"
	@printf "\t╰──────────────────────────────────────╯\n$(_END)"
