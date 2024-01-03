# Makefile for datastrlib

# Compilers flags
CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
LIB_DIR = $(BUILD_DIR)
LIB_NAME = datastrlib.a

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Test files
TEST_DIR = tests/unit
TEST_SRC_FILES = $(wildcard $(TEST_DIR)/test_*.c)
TEST_OBJ_FILES := $(TEST_SRC_FILES:$(TEST_DIR)/%.c=$(BUILD_DIR)/%.o)

.PHONY: all
# Targets
all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_FILES)
	ar rsc $(LIB_DIR)/$@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

.PHONY: test
test: $(TEST_OBJ_FILES) $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ -lcriterion
	./test --verbose

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/test_%.c
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

.PHONY: clean
clean:
	rm -vf $(BUILD_DIR)/*.o $(LIB_DIR)/$(LIB_NAME) test

