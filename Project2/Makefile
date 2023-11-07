# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -lm

# Source files
SOURCES = main.c route-records.c

# Executable name
EXECUTABLE = a.out

# Default target (build the executable)
all: $(EXECUTABLE)

# Build the executable
$(EXECUTABLE): $(SOURCES)
	$(CC) $^ $(CFLAGS) -o $@

# Clean up generated files
clean:
	rm -f $(EXECUTABLE)
