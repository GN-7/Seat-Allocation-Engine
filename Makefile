# ---- Configuration ----------------------------------------------------
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic-errors -g
SRC      := main.cpp
NAME     := josaa

# On Windows, MinGW's g++ appends .exe to the output. If the target name
# does not match the file actually produced, make rebuilds every time.
ifeq ($(OS),Windows_NT)
    EXE := .exe
else
    EXE :=
endif

TARGET := $(NAME)$(EXE)
DEBUG  := $(NAME)_debug$(EXE)

# ---- Default target: just run `make` ----------------------------------
# NOTE: every recipe line below MUST start with a real TAB, not spaces.
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# ---- Build and run in one step: `make run` ----------------------------
run: $(TARGET)
	./$(TARGET)

# ---- Strict build with sanitizers: `make debug` -----------------------
# Note: AddressSanitizer support on MinGW is patchy. If this fails to
# link on Windows, drop -fsanitize and rely on the warning flags.
debug: $(SRC)
	$(CXX) $(CXXFLAGS) -fsanitize=address,undefined -o $(DEBUG) $(SRC)
	./$(DEBUG)

# ---- Remove build products: `make clean` ------------------------------
clean:
	rm -f $(TARGET) $(DEBUG)

# ---- Show what make thinks it is doing: `make info` -------------------
info:
	@echo "compiler : $(CXX)"
	@echo "flags    : $(CXXFLAGS)"
	@echo "target   : $(TARGET)"

# ---- Targets that are commands, not files -----------------------------
.PHONY: run debug clean info
