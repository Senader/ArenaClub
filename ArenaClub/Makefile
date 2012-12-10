##
## Makefile for cat in /home/bourco_v//piscine/Jour_13/cat
## 
## Made by vincent bourcois
## Login   <bourco_v@epitech.net>
## 
## Started on  Wed Oct 24 14:09:59 2012 vincent bourcois
## Last update Mon Dec 10 15:51:41 2012 clery1 plassat
##

SRC		= main.c \
		int_to_char.c \
		functions.c \
		fight.c \
		my_strcpy.c \
		getfile.c \

NAME		= game

OBJ		= $(SRC:.c=.o)

LIB		= /u/all/bourco_v/rendu/lib/

LIBMLX		= -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		@cc -o $(NAME) $(OBJ) $(LIBMLX) -g

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		clean fclean all