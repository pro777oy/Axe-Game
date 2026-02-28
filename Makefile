CXX = clang++
SRC = axe_game.cpp
TARGET = axe_game

CFLAGS = -std=c++17 -O2 -Wall

RLFLAGS = -I/opt/homebrew/include \
          -L/opt/homebrew/lib -lraylib \
          -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CFLAGS) $^ $(RLFLAGS) -o $@

clean:
	rm -f $(TARGET)