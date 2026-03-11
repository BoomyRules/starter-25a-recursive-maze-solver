#include <iostream>
#include <utility>
#include <vector>

#include "solution.hpp"  // Your maze solver declarations

int main() {
  // Create a basic maze:
  // Row0: "#####"
  // Row1: "#   #"
  // Row2: "# # #"
  // Row3: "# #X#"
  // Row4: "#####"
  std::vector<std::vector<char>> maze = {{'#', '#', '#', '#', '#'},
                                         {'#', ' ', ' ', ' ', '#'},
                                         {'#', ' ', '#', ' ', '#'},
                                         {'#', ' ', '#', 'X', '#'},
                                         {'#', '#', '#', '#', '#'}};

  // Starting position: (1, 1)
  unsigned int start_row = 1;
  unsigned int start_col = 1;

  // Solve the maze
  auto solution_path = SolveMaze(maze, start_row, start_col);

  // Print the solution path directly in main()
  if (!solution_path.empty()) {
    std::cout << "Solution path:" << std::endl;
    for (const auto& coordinate : solution_path) {
      std::cout << "(" << coordinate.first << ", " << coordinate.second << ")"
                << std::endl;
    }
  } else {
    std::cout << "No solution found." << std::endl;
  }

  return 0;
}
