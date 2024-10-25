# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Target executable
TARGET = days_together

# Source and object files
SRCS = main.c date_calculator.c time_display.c
OBJS = $(SRCS:.c=.o)

# Default target to build the program
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean

