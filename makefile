CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Node.h LinkedList.h Card.cpp DeckOfCards.cpp HandOfCards.cpp Blackjack.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=3166360_Blackjack

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
