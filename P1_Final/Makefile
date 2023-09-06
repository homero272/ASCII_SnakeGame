OBJS	= main.o Profile.o Reader.o
SOURCE	= main.cpp Profile.cpp Reader.cpp
HEADER	= Profile.hpp Reader.hpp
OUT	= project1
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

Profile.o: Profile.cpp
	$(CC) $(FLAGS) Profile.cpp 

Reader.o: Reader.cpp
	$(CC) $(FLAGS) Reader.cpp 


clean:
	rm -f $(OBJS) $(OUT)
