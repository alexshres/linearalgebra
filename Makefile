
CXX = g++
FLAGS = -Wall -std=c++11
DFLAGS = -g	

PROG = mat


SRCS = main.cpp matrix.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = matrix.h


$(PROG): $(OBJS)
	$(CXX) $(FLAGS) $(DFLAGS) -o $(PROG) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CXX) $(FLAGS) $(DFLAGS) -c $< -o $@
	

clean:
	rm *.o $(PROG)


ga:
	git add .

gc:
	@read -p "Enter commit messages: " msg; \
		git commit -m "$$msg"

gp: ga gc
	git push
