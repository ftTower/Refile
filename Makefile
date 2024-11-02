# Nom de l'exécutable final et de la librairie
TARGET = refile
LIBNAME = librefile.a

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include -g3

# Répertoires
SRCDIR = ./src
UTILSDIR = $(SRCDIR)/utils
TFILEDIR = $(SRCDIR)/t_file
GNLDIR = $(UTILSDIR)/get_next_line
CONTENTDIR = $(SRCDIR)/content
INCDIR = ./include
BUILDDIR = ./build

# Fichiers source et objet
SRC = $(SRCDIR)/main.c $(GNLDIR)/get_next_line.c \
      $(TFILEDIR)/file_create.c \
      $(TFILEDIR)/file_print.c $(TFILEDIR)/file_display.c \
      $(CONTENTDIR)/content_create.c $(UTILSDIR)/utils_print.c
LIB_SRC = $(SRCDIR)/refile.c        # Source pour la librairie

# Fichiers objets pour l'exécutable et la librairie
OBJ = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRC))
LIB_OBJ = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(LIB_SRC))

# Couleurs pour les messages
COLOR_GREEN = \033[32m
COLOR_BLUE = \033[34m
COLOR_RESET = \033[0m

# Règle par défaut
all: $(TARGET)

# Règle pour compiler l'exécutable
$(TARGET): $(OBJ) $(LIBNAME)
	@echo "$(COLOR_BLUE)[Linking]$(COLOR_RESET) Creating $(TARGET) with $(LIBNAME)"
	@$(CC) $(OBJ) -L. -lrefile -o $(TARGET)
	@echo "$(COLOR_GREEN)✔ $(TARGET) is ready.$(COLOR_RESET)"

# Règle pour compiler la librairie statique
$(LIBNAME): $(LIB_OBJ)
	@echo "$(COLOR_BLUE)[Library]$(COLOR_RESET) Creating $(LIBNAME)"
	@ar rcs $(LIBNAME) $(LIB_OBJ)
	@echo "$(COLOR_GREEN)✔ $(LIBNAME) created.$(COLOR_RESET)"

# Compilation des fichiers .o et création du dossier build s'il n'existe pas
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)  # Créer le répertoire de destination si nécessaire
	@echo "$(COLOR_BLUE)[Compiling]$(COLOR_RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et le dossier build
clean:
	@rm -f $(OBJ) $(LIB_OBJ)
	@rm -rf $(BUILDDIR)
	@echo "$(COLOR_GREEN)✔ Cleaned build files.$(COLOR_RESET)"

# Règle pour tout nettoyer, y compris l'exécutable et la librairie
fclean: clean
	@rm -f $(TARGET) $(LIBNAME)
	@echo "$(COLOR_GREEN)✔ Cleaned all, including $(TARGET) and $(LIBNAME).$(COLOR_RESET)"

# Règle pour recompilation complète
re: fclean all

# Phony targets pour éviter les conflits avec des fichiers portant les mêmes noms
.PHONY: all clean fclean re
