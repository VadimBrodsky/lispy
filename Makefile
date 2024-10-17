# Define variables
CC = cc
CFLAGS = -std=c99 -Wall

# Build rule: takes a .c file as input and produces a corresponding .out file
build:
	@if [ -z "$(file)" ]; then \
		echo "Usage: make build file=<source_file.c>"; \
		exit 1; \
	fi
	$(CC) $(CFLAGS) $(file) -o $(basename $(file)).out

# Clean target to remove all .out files
clean:
	rm -f *.out

# Phony targets to avoid conflicts with files named 'build' or 'clean'
.PHONY: build clean

