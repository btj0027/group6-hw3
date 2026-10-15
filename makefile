CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
TARGET   := main

SRCS := main.cpp address.cpp credit_card.cpp person.cpp product.cpp store.cpp transaction.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# -MMD -MP generates .d files so objects rebuild when included headers change
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
