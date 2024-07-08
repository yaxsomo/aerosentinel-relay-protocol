# build/Makefile

CC=gcc
CFLAGS=-I../src -I../src/interface -I../src/transport -I../src/physical -I../src/common
SRC_DIR=../src
OBJ_DIR=obj

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.c) \
       $(wildcard $(SRC_DIR)/protocol/*.c) \
       $(wildcard $(SRC_DIR)/protocol/examples/*.c) \
       $(wildcard $(SRC_DIR)/application_layer/*.c) \
       $(wildcard $(SRC_DIR)/network_layer/*.c) \
       $(wildcard $(SRC_DIR)/data_link_layer/*.c) \
       $(wildcard $(SRC_DIR)/physical_layer/*.c)

# List of object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Target executable
TARGET = arp_protocol

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(TARGET) $(OBJ_DIR)
