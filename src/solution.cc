#include "solution.hpp"

bool TryMove(const std::vector<std::vector<char>>& maze,
             int next_row,
             int next_col,
             std::vector<std::pair<unsigned int, unsigned int>>& path,
             std::vector<std::vector<bool>>& visited) {
  if (next_row < 0 || next_col < 0 ||
      next_row >= static_cast<int>(maze.size()) ||
      next_col >= static_cast<int>(maze[0].size())) {
    return false;
  }

  if (visited[next_row][next_col]) {
    return false;
  }

  if (maze[next_row][next_col] == '#') {
    return false;
  }

  return SolveMazeRecursive(maze,
                            static_cast<unsigned int>(next_row),
                            static_cast<unsigned int>(next_col),
                            path,
                            visited);
}

std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_row,
    unsigned int start_col) {
  std::vector<std::pair<unsigned int, unsigned int>> path;
  unsigned int rows = maze.size();
  unsigned int cols = maze[0].size();
  std::vector<bool> row(cols, false);
  std::vector<std::vector<bool>> visited(rows, row);

  SolveMazeRecursive(maze, start_row, start_col, path, visited);

  return path;
}

bool SolveMazeRecursive(
    const std::vector<std::vector<char>>& maze,
    unsigned int row,
    unsigned int col,
    std::vector<std::pair<unsigned int, unsigned int>>& path,
    std::vector<std::vector<bool>>& visited) {
  visited[row][col] = true;
  path.push_back({row, col});

  if (maze[row][col] == 'X') {
    return true;
  }

  int row_i = static_cast<int>(row);
  int col_i = static_cast<int>(col);

  if (TryMove(maze, row_i + 1, col_i, path, visited)) {
    return true;
  }
  if (TryMove(maze, row_i - 1, col_i, path, visited)) {
    return true;
  }
  if (TryMove(maze, row_i, col_i + 1, path, visited)) {
    return true;
  }
  if (TryMove(maze, row_i, col_i - 1, path, visited)) {
    return true;
  }

  path.pop_back();
  return false;
}