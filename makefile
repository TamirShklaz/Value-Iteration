PROG = bin/*

OBJS = obj/*
INCLUDE = -ITools
.PHONY: clean As5 run
all:    clean As5 run

CC = g++

As5:
	$(CC) -c main.cpp -o ./bin/main.o
	$(CC) -c State.cpp -o ./bin/State.o
	$(CC) -c Action.cpp -o ./bin/Action.o
	$(CC) -o bin/As5 bin/main.o bin/State.o bin/Action.o

run:
	bin/As5