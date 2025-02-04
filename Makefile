FCT = ft_putchar.c ft_atoi.c ft_putnbr.c ft_putstr.c

SRV = server.c
CLT = client.c
BSRV = server_bonus.c
BCLT = client_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(FCT:.c=.o)

XSRV = server
XCLT = client
XBSRV = server_bonus
XBCLT = client_bonus

NAME = $(XSRV) $(XCLT)
BONUS = $(XBSRV) $(XBCLT) 

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(SRV) -o $(XSRV)
	@$(CC) $(CFLAGS) $(OBJ) $(CLT) -o $(XCLT)

bonus : fclean $(BONUS)

$(BONUS) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(BSRV) -o $(XBSRV)
	@$(CC) $(CFLAGS) $(OBJ) $(BCLT) -o $(XBCLT)

%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ) 

fclean : clean
	@$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY : clean
