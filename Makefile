CXX = g++
CXXFLAGS = -I./include
DIST_DIR = dist
TARGET = $(DIST_DIR)/aliases
SRC_DIR = src
INCLUDE_DIR = include
SRC_FILES = $(SRC_DIR)/**/*.cpp main.cpp

all: $(DIST_DIR) $(TARGET)

$(DIST_DIR):
	mkdir -p $(DIST_DIR)

$(TARGET): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC_FILES)

clean:
	rm -rf $(DIST_DIR)
