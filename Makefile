# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Target executable
TARGET = main

# Source files and object files
SRCS = main.cpp log.cpp VertexTensor.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)