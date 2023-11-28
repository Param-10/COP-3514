# Name: Paramveer Singh Bhele
# UNumber: U82076898
# Description: Project 10 - Part 2
# The purpose of this makefile is to build the Project 10 - Part 2 program. 
# It compiles the following source files: guest.c, read_line.c, and project10_guests.c.
# The compiled object files (guest.o, read_line.o, and project10_guests.o) are linked together to form the project10_guests.
# The makefile contains instructions for creating individual object files, linking them, and cleaning up the resulting files.
# -'make clean': This command removes the compiled object files as well as the executed file.

# The rules to be followed according to the question 
CC: gcc
project10_guests: guest.o read_line.o project10_guests.o
	$(CC) guest.o read_line.o project10_guests.o -o project10_guests

project10_guests.o: project10_guests.c 
	$(CC) -Wall -std=c99 -c project10_guests.c -o project10_guests.o

guest.o: guest.c 
	$(CC) -Wall -std=c99 -c guest.c -o guest.o

read_line.o: read_line.c 
	$(CC) -Wall -std=c99 -c read_line.c -o read_line.o

# This command is used for cleaning the makefile. 
#It runs a series of commands that delete any generated or temporary files that were created during the compilation process.
clean:
	rm -f read_line.o guest.o project10_guests.o project10_guests