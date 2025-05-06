CXX = g++
CXXFLAGS = -std=c++23 -Iinclude
LDFLAGS = -lgdi32 -luser32
SRC = src/draw.cpp src/point.cpp src/shapes/circle.cpp src/shapes/square.cpp src/shapes/triangle.cpp main.cpp

.PHONY: all clean

all: main

main: $(SRC)
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(LDFLAGS)

clean:
	rm -f main