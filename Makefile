CC = cc
FLAGS = -Wall -Wextra -Werror 
SERVER = server
CLIENT = client
HEADER = minitalk.h
SRC = utils.c utils1.c
OBJS = $(SRC:.c=.o)

CLIENT_SRC = utils.c utils1.c client.c
SERVER_SRC = utils.c utils1.c server.c
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)
NAME = server client

all : $(NAME)

$(NAME) : $(CLIENT_OBJS) $(SERVER_OBJS)
	@$(CC) $(FLAGS) $(SERVER_OBJS) -o server
	@echo "\033[32m----server.c compiled!----\033[0m" 
	@$(CC) $(FLAGS) $(CLIENT_OBJS) -o client
	@echo "\033[32m----client.c compiled!----\033[0m" 

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "\033[33m----Cleaning!----\033[0m" 
	@echo "-----------------" 
	@rm -rf $(CLIENT_OBJS) $(SERVER_OBJS)
	@echo "\033[32m----Mr.Clean!----\033[0m" 

fclean: clean
	@echo "\033[33m----Cleaning!----\033[0m"
	@echo "-----------------" 
	@rm -rf $(SERVER) $(CLIENT) 
	@echo "\033[32m----MR.Clean!----\033[0m"

re: fclean all
	@echo "\033[32m----Rebuild done!----\033[0m" 