CXX = g++

SOURCES = main.cpp Food.cpp
TARGET = eatclean

$(TARGET): $(SOURCES)
	$(CXX) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)
