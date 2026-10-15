CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = main

SRCS = main.cpp address.cpp credit_card.cpp person.cpp product.cpp store.cpp transaction.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)