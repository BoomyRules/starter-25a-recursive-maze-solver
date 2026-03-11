#ifndef SOLUTION_HPP
#define SOLUTION_HPP
#include <utility>
#include <vector>

std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_row,
    unsigned int start_col);

bool SolveMazeRecursive(
    const std::vector<std::vector<char>>& maze,
    unsigned int row,
    unsigned int col,
    std::vector<std::pair<unsigned int, unsigned int>>& path,
    std::vector<std::vector<bool>>& visited);

#endif