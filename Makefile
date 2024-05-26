.PHONY: clean
# Compiler
COMPILER = g++
CFLAGS = -std=c++20 -O3
# Linker
LINKER = $(COMPILER) -lm
# Executable name
EXEC = HW7
# Object files
OBJ = HW7.o
# Default target
all: $(EXEC)
# Link object files to create the executable $(EXEC): $(OBJ)
$(EXEC): $(OBJ)
	$(LINKER) -o $@ $^
%.o: %.cpp SimpleSet.h
	$(COMPILER) $(CFLAGS) -c $< -o $@ 
clean:
	rm -f $(OBJ) $(EXEC)