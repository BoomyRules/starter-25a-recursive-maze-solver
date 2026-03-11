CXX=clang++
CXX_FLAGS=-std=c++20 -I ./includes -Wall -Wextra -Werror -Wno-unused-parameter -pedantic -O0 -g

exec: bin/exec

bin/exec: ./src/driver.cc ./includes/solution.hpp ./src/solution.cc
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/solution.cc -fsanitize=address -o $@

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -rf bin/*