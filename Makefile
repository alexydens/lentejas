PROJECT_NAME=kernel
SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj
BIN_DIR=bin
CROSS_DIR=../cross

PREFIX=$(CROSS_DIR)/bin/x86_64-elf-
CC=$(PREFIX)gcc
AS=$(PREFIX)as
LD=$(PREFIX)ld

CFLAGS = -Wall -Wextra -Wpedantic -Werror -Wno-unused -std=c11 -ggdb -I$(INC_DIR)
CFLAGS += -ffreestanding -fno-pie
LDFLAGS = -z max-page-size=4096 -T linker.ld -nostdlib

C_SOURCES = $(wildcard $(SRC_DIR)/*.c)
ASM_SOURCES += $(wildcard $(SRC_DIR)/*.S)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_SOURCES))
OBJECTS += $(patsubst $(SRC_DIR)/%.S, $(OBJ_DIR)/%.o, $(ASM_SOURCES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.S | $(OBJ_DIR)
	$(AS) $(CFLAGS) -c $< -o $@
$(BIN_DIR)/$(PROJECT_NAME): $(OBJECTS) | $(BIN_DIR)
	$(LD) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJ_DIR):
	mkdir -p $@
$(BIN_DIR):
	mkdir -p $@

.PHONY: clean build test

build: $(BIN_DIR)/$(PROJECT_NAME)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)

test: build
