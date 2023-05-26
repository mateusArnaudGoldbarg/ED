#!/bin/bash

g++ -c maior.cpp
g++ -c main.cpp

g++ maior.o main.o -o program

./program
