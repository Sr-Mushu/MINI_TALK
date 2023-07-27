# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 14:35:56 by dagabrie          #+#    #+#              #
#    Updated: 2023/01/12 14:50:20 by dagabrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	minitalk
CLIENT		=	client
SERVER		=	server

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f
MKD			=	mkdir
INC			=	-I ./Libft -I ./Printf

LIBFT = ./libft-minitalk/libft.a
LIBFT_PATH = ./libft-minitalk

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

SRC_NAME	=	client.c	\
				server.c

SRC_PATH = .
OBJ_PATH = ./objects

OBJ	= 	$(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
SRC	=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)

$(LIBFT): $(shell make -C $(LIBFT_PATH) -q libft.a)
	make -C $(LIBFT_PATH)

$(FT_PRINTF): $(shell make -C $(FT_PRINTF_PATH) -q libftprintf.a)
	make -C $(FT_PRINTF_PATH)

$(SERVER) : objects/server.o
	$(CC) $(CFLAGS) objects/server.o $(INC) $(LIBFT) $(FT_PRINTF) -o $(SERVER)

$(CLIENT) : objects/client.o
	$(CC) $(CFLAGS) objects/client.o $(INC) $(LIBFT) $(FT_PRINTF) -o $(CLIENT)

$(NAME) : $(LIBFT) $(FT_PRINTF) $(CLIENT) $(SERVER)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(MKD) -p objects
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(FT_PRINTF_PATH)
	make clean -C $(LIBFT_PATH)
	$(RM) -rf $(OBJ_PATH)

fclean: clean
		make fclean -C $(LIBFT_PATH)
		make fclean -C $(FT_PRINTF_PATH)
		$(RM) $(NAME)
		$(RM) $(CLIENT)
		$(RM) $(SERVER)
re: fclean all

.PHONY:	all clean fclean re force