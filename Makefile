CXX = g++
CXXFLAGS = -std=c++17
TARGET = app
SOURCES = main.cpp message.cpp user.cpp
OBJECTS = $(SOURCES:.cpp=.o)


$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
	chmod 6755 $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJECTS) $(TARGET) users messages


.PHONY: clean
