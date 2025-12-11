# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiezhang <jiezhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/22 16:40:34 by jiezhang          #+#    #+#              #
#    Updated: 2025/11/30 09:44:49 by jiezhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# the compiler to user
CC = cc

# compiler flag: show all warnings, extra warnings, treat warning as errors
# -I. search headers in current folder, it tells the compiler where to look for .h file
CFLAGS = -Imandatory -Wall -Wextra -Werror -g3 -O0

# define archiver, commond to create a static library
# ar: create .a static library
# r: replace or add files, c: create the archiver, s: write an index (symbol table)

# delete files
RM = rm -f

# name of the excutable file
NAME = push_swap
BONUS = checker

# define header
HEADER = mandatory/push_swap.h bonus/checker.h

# list of source files
MANDATORY_SRCS = mandatory/calculate_costs.c mandatory/find_lis.c mandatory/index_stack.c  mandatory/push_back.c mandatory/push_swap_utils.c \
		mandatory/sort_small.c mandatory/main.c\

BONUS_SRCS = bonus/checker.c bonus/checker_utils.c

SHARED_SRCS = mandatory/parse_args.c mandatory/push_swap.c mandatory/push.c mandatory/reverse_rotate.c mandatory/rotate.c \
		mandatory/swap.c mandatory/stack.c mandatory/ft_split.c

# replace all .c extension with .o to get object files
MANDATORY_OBJ = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)
SHARED_OBJ = $(SHARED_SRCS:.c=.o)

# run make
all: $(NAME)

bonus: $(BONUS)

# build rule 
# target is $(NAME) $(BONUS)(excutable file), dependence are $(OBJ) (object files)
$(NAME):$(MANDATORY_OBJ) $(SHARED_OBJ)
	$(CC) $(CFLAGS) $(MANDATORY_OBJ) $(SHARED_OBJ) -o $(NAME)

$(BONUS): $(BONUS_OBJ) $(SHARED_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(SHARED_OBJ) -o $(BONUS)

# pattern rule: compile each .c into .o
# % matches any filename stem.
# $<: the first dependency eg: .c files; $@: the target eg: .o file
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
# remove all object files
clean:
	$(RM) $(MANDATORY_OBJ) $(BONUS_OBJ) $(SHARED_OBJ)

#remove object files and the final library and excutables
fclean: clean
	$(RM) $(NAME) $(BONUS)

# rebuild everything from sractch
re: fclean all

#declare non-flie targets to avoid conflicts
#.PHONY declares phony targets, targets do not represent real files
#"they are just commands, not files always run when requested"
.PHONY: all clean fclean re bonus