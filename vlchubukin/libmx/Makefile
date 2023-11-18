NAME	=	libmx.a

CFLG	=	-std=c11 -Wall -Wextra -Werror -Wpedantic
COMP 	= 	clang

SRCD	=	src
INCD	=	inc
OBJD	=	obj

INC		=	libmx.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC = $(wildcard $(SRCD)/*.c)

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS = $(addprefix $(OBJD)/, $(notdir $(SRC:%.c=%.o)))

all: install
	
install: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^

$(OBJD)/%.o: $(SRCD)/%.c $(INCS) | $(OBJD)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@
	
clean:
	@rm -rf $(OBJD)

uninstall: clean
	@rm -rf $(NAME)

reinstall: uninstall install

start: 
	$(COMP) $(CFLG) main.c libmx.a && ./a.out

start_i: install
	$(COMP) $(CFLG) main.c libmx.a && ./a.out