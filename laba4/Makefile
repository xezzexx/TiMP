CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11
OBJ = build/main.o build/transport.o build/car.o build/airplane.o
TARGET = build/transport
HEAD_DIR = src/head
BUILD_DIR = build

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

$(BUILD_DIR)/main.o: src/main.cpp $(HEAD_DIR)/transport.h $(HEAD_DIR)/car.h $(HEAD_DIR)/airplane.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/transport.o: src/transport.cpp $(HEAD_DIR)/transport.h
	$(CXX) $(CXXFLAGS) -c src/transport.cpp -o $(BUILD_DIR)/transport.o

$(BUILD_DIR)/car.o: src/car.cpp $(HEAD_DIR)/car.h $(HEAD_DIR)/transport.h
	$(CXX) $(CXXFLAGS) -c src/car.cpp -o $(BUILD_DIR)/car.o

$(BUILD_DIR)/airplane.o: src/airplane.cpp $(HEAD_DIR)/airplane.h $(HEAD_DIR)/transport.h
	$(CXX) $(CXXFLAGS) -c src/airplane.cpp -o $(BUILD_DIR)/airplane.o

clean: 
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/transport