##########################################################
# Makefile
# CS480, Summer 2026
# Programming Assignment #1
# Alice Hua and Brianna Garcia

# Class Accounts:
# Brianna: cssc3122
# Account that is used Alice:cssc3124
###########################################################


EXEC = bots
CXX = g++

$(EXEC): bots.cpp bots.hpp
	$(CXX) -pthread -o $(EXEC) bots.cpp

clean:
	rm -f *.o core a.out $(EXEC) QUOTE.txt

###############[ EOF: Makefile]#############################

