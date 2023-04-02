# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 18:59:33 by idabligi          #+#    #+#              #
#    Updated: 2023/02/06 13:16:58 by idabligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client

NAME_b = server_bonus
NAME_b2 = client_bonus

CC = cc
FLAGS =  -Wall -Wextra -Werror
RM = rm -f

FLS_server =  server minitalk_utils convert\

FLS_client =  client minitalk_utils convert\

FLS_server_b =  server_bonus minitalk_utils_bonus convert_bonus\

FLS_client_b =  client_bonus minitalk_utils_bonus convert_bonus\

FO_server = $(FLS_server:=.o)
FO_client = $(FLS_client:=.o)


FO_server_b = $(FLS_server_b:=.o)
FO_client_b = $(FLS_client_b:=.o)

all : $(NAME) $(NAME2)

$(NAME) : $(FO_server)  header.h
	$(CC) $(FO_server) -o $(NAME)

$(NAME2): $(FO_client) header.h
	$(CC) $(FO_client) -o $(NAME2)
	
bonus : $(NAME_b) $(NAME_b2) 
	
$(NAME_b) : $(FO_server_b) header_bonus.h
	$(CC) $(FO_server_b) -o $(NAME_b)

$(NAME_b2) : $(FO_client_b) header_bonus.h
	$(CC) $(FO_client_b) -o $(NAME_b2)

%.o:%.c header.h header_bonus.h
	$(CC) -c $(FLAGS) $<

clean :
	$(RM) $(FO_server) $(FO_client) $(FO_server_b) $(FO_client_b)

fclean : clean
	$(RM) $(NAME) $(NAME2) $(NAME_b) $(NAME_b2)

re : fclean all

.PHONY : all clean fclean re