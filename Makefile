NAME        = libftprintf.a
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
# 包含当前目录和 libft 目录的头文件
INCLUDES    = -I. -I$(LIBFT_DIR)

SRCS        = ft_printf.c utils.c # 你的源码文件
OBJS        = $(SRCS:.c=.o)

# 默认规则
all: $(NAME)

# 核心：如何生成 libftprintf.a
$(NAME): $(LIBFT) $(OBJS)
	@# 将 libft.a 拷贝一份改名为 libftprintf.a
	cp $(LIBFT) $(NAME)
	@# 将 ft_printf 自己的 .o 文件添加到这个库里
	ar rcs $(NAME) $(OBJS)

# 强制进入 libft 目录执行 make
$(LIBFT):
	make -C $(LIBFT_DIR)

# 编译 .c 到 .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
