# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 16:20:46 by emimenza          #+#    #+#              #
#    Updated: 2024/04/22 16:20:46 by emimenza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = sudo c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 
RM = sudo rm -rf
NAME = phonebook

SRCS = srcs/Contact.cpp\
	   srcs/PhoneBook.cpp\
	   main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run

#.SILENT: