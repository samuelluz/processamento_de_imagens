# Makefile

# Project Name
PROJ_NAME := webcam.out

# Compiler and linker
CC := gcc

# Compiler and linker
CXX := g++

# SOURCE folder
SRC_DIR := src

# HEADER folder
INC_DIR := ./inc

# Build folder
BUILD_DIR := build

FLAG_OPENCV := `pkg-config --cflags --libs opencv`

# Source files C++
SRCSXX := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS := $(patsubst %.cpp,%.o, $(SRCSXX))

# Project dependences
PROJ_DEP := -std=c++17 \
			-std=gnu++17 \
			 $(FLAG_OPENCV) \


all: folders $(PROJ_NAME)

$(PROJ_NAME): $(OBJS)
	@echo "Linking $^ ..."
	$(CXX) $^ -o $(BUILD_DIR)/$@ $(PROJ_DEP)
	@echo "\033[92mBinary are ready in $(BUILD_DIR)/$@!\033[0m"

%.o: %.c
	@echo "Compiling $^ ..."
	$(CC) -O0 -g -c $^ -o $@ -I$(INC_DIR) -I/usr/local/include/opencv4
	@echo "\033[94m$@ Compiled!\033[0m"

%.o: %.cpp
	@echo "Compiling $^ ..."
	$(CXX) -O0 -g -c $^ -o $@ -I$(INC_DIR) -I/usr/local/include/opencv4
	@echo "\033[94m$@ Compiled!\033[0m"

folders:
	@mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(BUILD_DIR)/* $(SRC_DIR)/*.o $(BUILD_DIR) *.deb
