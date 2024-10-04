#Makefile for video game library
 
all                 :   Driver
 
Driver            :   Driver.o VideoGame.o VideoGameLibrary.o Text.o
                        g++ -std=c++11 -o Driver.exe Driver.o VideoGame.o VideoGameLibrary.o Text.o
 
Driver.o          :   Driver.cpp
                        g++ -std=c++11 -I ./ -c Driver.cpp
               
VideoGame.o         :   VideoGame.cpp
                        g++ -std=c++11 -I ./ -c VideoGame.cpp
           
VideoGameLibrary.o  :   VideoGameLibrary.cpp
                        g++ -std=c++11 -I ./ -c VideoGameLibrary.cpp
           
Text.o              :   Text.cpp
                        g++ -std=c++11 -I ./ -c Text.cpp