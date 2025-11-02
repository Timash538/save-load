CXX = g++
CXXFLAGS = -std=c++17
TARGET = app
SOURCES = main.cpp message.cpp
OBJECTS = $(SOURCES:.cpp=.o)


$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJECTS) $(TARGET)


.PHONY: clean
