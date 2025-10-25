# ================================
# VARIABLES AND CONFIGURATION
# ================================

# Executable
NAME = cub3D

# Directory
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
OBJS_DIR = objects

# Sources files
SRCS = 0_cub3D.c \
	0_free_cub_and_close.c \
	1_is_name_file_correct.c \
	2_first_opening_file.c \
	3_is_data_file_correct.c \
	4_fill_map.c \
	5_is_data_cub_file_valid.c \
	6_is_all_elements_presents.c \
	7_check_wall_textures.c \
	8_check_floor_ceiling_and_map.c \
	9_error_message_check.c \
	10_is_wall_textures_valid.c \
	11_textures_NO_valid.c \
	12_textures_SO_valid.c \
	13_textures_WE_valid.c \
	14_textures_EA_valid.c \
	15_error_message_textures.c






# Object files (objects/<path>.o)
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
# OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

# Compilation and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MLX_DIR)

# Library
LIBFT = -L$(LIBFT_DIR) -lft
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Output settings (colors)
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
NC = \033[0m
BOLD_UNDERLINE = \033[1;4m

# ================================
# COMPILATION
# ================================

# Default target
all: $(NAME)
	@printf "$(GREEN)$(BOLD_UNDERLINE)✓ Compilation terminée avec succès !$(NC)\n"

# Link the executable
$(NAME): $(OBJS) | libft
	@printf "$(BLUE)🔗 Linking $(NAME)$(NC)\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)

# Compile each .o from .c (preserving folders, handling dots)
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)🔨 Compilation de $<$(NC)\n"
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft
libft:
	@printf "$(BLUE)📚 Compilation de libft...$(NC)\n"
	$(MAKE) -C $(LIBFT_DIR)

# ================================
# CLEANING
# ================================

clean:
	@printf "$(RED)🧹 Suppression des fichiers objets...$(NC)\n"
	rm -rf $(OBJS_DIR)

fclean: clean
	@printf "$(RED)🗑️  Suppression de l’exécutable...$(NC)\n"
	rm -f $(NAME)

clean_libft:
	@printf "$(RED)🧹 Suppression des objets de libft...$(NC)\n"
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)

fclean_libft: clean_libft
	@printf "$(RED)🗑️  Suppression de l’exécutable et libft...$(NC)\n"
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# ================================
# RECOMPILATION
# ================================

re: fclean all
re_libft: fclean_libft all

# ================================
# PHONY
# ================================

.PHONY: all clean fclean clean_libft fclean_libft re re_libft libft
