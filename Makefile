CC = g++
CFLAG =

all : part1.exe part2.exe part3.exe

part1.exe : part1.o part1_main.o
	$(CC) $(CFLAG) -o part1.exe part1.o part1_main.o

part1.o : part1.cpp
	$(CC) $(CFLAG) -c part1.cpp

part1_main.o : part1_main.cpp
	$(CC) $(CFLAG) -c part1_main.cpp

part2.exe : part2.cpp
	$(CC) $(CFLAG) -o part2.exe part2.cpp

part3.exe : part3.cpp
	$(CC) $(CFLAG) -o part3.exe part3.cpp 
