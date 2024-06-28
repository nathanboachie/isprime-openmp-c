# Compiler and flags
CXX = gcc
CXXFLAGS = -O3 -fopenmp
LDFLAGS = -lm

# Directories
SRC_DIR = src
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/prime

# Default target
default: all

# All target
all: create_directory $(TARGET)

# Create the bin directory if it doesn't exist
create_directory:
	@mkdir -p $(BIN_DIR)

# Compile the source file into the target executable
$(TARGET): $(SRC_DIR)/prime.c
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS)

# Clean target to remove the binary
clean:
	rm -f $(TARGET)
