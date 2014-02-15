#  Info:       Makefile Template Design for c++ compilations specifically targeting c++11
#  Created:    07.July.2013
#  Modified:   25.July.2013
#  Author:     James Muldoon

# Which compiler to use:
#	gcc		for C program
#	g++		for C++ program
CXX=g++

# Directories which are to be used
SDIR =src
ODIR =obj
IDIR =inc

# The build target executable
TARGET = QueueTest

# Setup macro definitions
INCLUDES = -I$(IDIR)
SOURCES  = $(wildcard $(SDIR)/*.cpp)
OBJS = $(addprefix $(ODIR)/, $(notdir $(SOURCES:.cpp=.o)))

# Compiler flags:
#	-g 		adds debugging information to the executable file
#	-Wall		turns on most, but not all, compiler warnings
#	-I.		gcc will look in the current directory (.) for the include file(s)
#	-pthread	allows system threads to be used.
CXXFLAGS = -Wall -std=c++0x -pthread -g $(INCLUDES)
LDFLAGS = -lm

# Build command all
all: $(ODIR)/$(TARGET)

# Generate the actual executable through the use of the object files.
$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Generate the actual executable through the use of the object files.
$(ODIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) -o $@

# Ensures that the rule below is followed and not another clean is executed
.PHONY: clean

# Removes the object file, backup files, core dumps, and the executable by "make clean"
clean:
	$(RM) $(ODIR)/*.o *~ core $(ODIR)/$(TARGET) $(ODIR)/$(TARGET).exe $(INCDIR)/*~
