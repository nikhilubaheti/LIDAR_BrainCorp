CXX ?= g++
INCLUDES = -I ..

all:
	$(CXX) -std=gnu++11 $(INCLUDES) Robot.cpp LIDAR.cpp RangeFilter.cpp TemporalMedianFilter.cpp TestCase.cpp -o Robot

clean:
	rm Robot