# COLORS
BOLD = "\e[1m"
REGULAR = "\e[0m"
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"
PURPLE = "\033[35m"
CYAN = "\033[36m"
WHITE = "\033[37m"

# FUNCTIONS
define p_echo
	@echo $(GREEN)$(BOLD)$(1)$(REGULAR)
endef


# COMPILER
CC = gcc
WFLAGS = -Wall -Wextra -Werror

# DIRS
DIST = build
BIN = $(DIST)/bin
OBJ = $(DIST)/obj
SOURCE = src
MODULES = $(SOURCE)/modules

# FILES
DEPENDECIES = $(DIST)/ $(patsubst $(MODULES)/%.c, $(OBJ)/%.o, $(wildcard $(MODULES)/*.c)) $(OBJ)/main.o
TARGET = main

# COMPILE MAIN FILE
$(BIN)/$(TARGET): $(DEPENDECIES)
	$(call p_echo,"[COMPILING ALL]")

	$(CC) $(WFLAGS) \
	$(OBJ)/*.o \
	-o $(BIN)/$(TARGET)

	@echo

# CREATE DIST FOLDERS
$(DIST)/:
	$(call p_echo,"[CREATING DIST FOLDERS]")

	mkdir $(DIST)/ $(BIN)/ $(OBJ)/

	@echo

# COMPILE MODULES
$(OBJ)/%.o: $(MODULES)/%.h $(MODULES)/%.c
	$(call p_echo,"[COMPILING MODULE] $*")

	$(CC) $(WFLAGS) -c \
	$(MODULES)/$*.c

	mv $*.o \
	$(OBJ)

	@echo

# COMPILE main
$(OBJ)/main.o: $(SOURCE)/main.c
	$(call p_echo,"[COMPILING MAIN]")

	$(CC) $(WFLAGS) -c \
	$(SOURCE)/main.c

	mv main.o \
	$(OBJ)

	@echo

# CLEAN
clean:
	$(call p_echo,"[CLEANING OBJECTS]")

	rm -rf \
	$(OBJ)/*.o

	@echo

# HARDCLEAN
hardclean:
	$(call p_echo,"[CLEANING ALL DIST STUFF]")

	rm -r \
	$(DIST)/

	@echo

# RUN CODE
run: $(BIN)/$(TARGET)
	$(call p_echo,"[RUNNING] $(TARGET)")
	
	$(BIN)/$(TARGET)

	@echo

# TEST
test:
	$(call p_echo,"Hello")