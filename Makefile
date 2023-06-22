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
	@echo "[COMPILING ALL]"

	$(CC) $(WFLAGS) \
	$(OBJ)/*.o \
	-o $(BIN)/$(TARGET)

	@echo

# CREATE DIST FOLDERS
$(DIST)/:
	@echo "[CREATING DIST FOLDERS]"

	mkdir $(DIST)/ $(BIN)/ $(OBJ)/

	@echo

# COMPILE MODULES
$(OBJ)/%.o: $(MODULES)/%.h $(MODULES)/%.c
	@echo "[COMPILING MODULE] $*"

	$(CC) $(WFLAGS) -c \
	$(MODULES)/$*.c

	mv $*.o \
	$(OBJ)

	@echo

# COMPILE main
$(OBJ)/main.o: $(SOURCE)/main.c
	@echo "[COMPILING MAIN]"

	$(CC) $(WFLAGS) -c \
	$(SOURCE)/main.c

	mv main.o \
	$(OBJ)

	@echo

# CLEAN
clean:
	@echo "[CLEANING OBJECTS]"

	rm -rf \
	$(OBJ)/*.o

	@echo

# HARDCLEAN
hardclean:
	@echo "[CLEANING ALL DIST STUFF]"

	rm -r \
	$(DIST)/

	@echo

# RUN CODE
run: $(BIN)/$(TARGET)
	@echo "[RUNNING $(TARGET)]"
	
	$(BIN)/$(TARGET)

	@echo

# TEST
test:
	@echo "$(DEPENDECIES)"