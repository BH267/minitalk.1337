FCT = ft_putchar.c ft_atoi.c ft_putnbr.c ft_putstr.c
SRV = server.c
CLT = client.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

XSRV = server
XCLT = client

all : $(XSRV) $(XCLT)

$(XSRV) :
	@$(CC) $(CFLAGS) $(FCT) $(SRV) -o $@

$(XCLT) :
	@$(CC) $(CFLAGS) $(FCT) $(CLT) -o $@

clean :

fclean : clean
	@rm -f $(XCLT) $(XSRV)

re : fclean all

.PHONY : clean
