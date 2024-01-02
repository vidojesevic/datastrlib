# Makefile for datastrlib

# Compilers flags
CC = gcc
CFLAGS = -g -Wall -Wextra -sdt=c11

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
LIB_DIR = $(BUILD_DIR)
LIB_NAME = datastrlib.a

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILEs))

# Targets
all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_FILES)
	ar rsc $(LIB_DIR)/$@ $^

$(BUILD_DIR)/%.c: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

clean:
	rm -vf $(BUILD_DIR)/*.o $(LIB_DIR)/$(LIB_NAME)

.PHONY: all clean
