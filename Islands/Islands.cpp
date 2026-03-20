#include <vector>
#include <assert.h>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

int count_islands(std::vector<std::vector<char>>& grid)
{
    int island_count = 0;
    bool isFirstLand = false;
    
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            if (grid[row][col] == '0') continue;

            if (!isFirstLand) {
                island_count++;
                isFirstLand = true;
            }
            
            bool adjacentLand = false;
            
            if (row < grid.size() - 1) {
                if (grid[row + 1][col] == '1') {
                    adjacentLand = true;
                }
            }
            if (row > 0) {
                if (grid[row - 1][col] == '1') {
                    adjacentLand = true;
                }
            }
            if (col < grid[0].size() - 1) {
                if (grid[row][col + 1] == '1') {
                    adjacentLand = true;
                }
            }
            if (col > 0) {
                if (grid[row][col - 1] == '1') {
                    adjacentLand = true;
                }
            }

            if (!adjacentLand) {
                island_count++;
            }

            
        }
    }
    
	return island_count;
}

int main()
{
    {
        std::vector<std::vector<char>> grid = {
            {'1','1','0','0'},
            {'1','1','0','0'},
            {'0','0','1','0'},
            {'0','0','0','1'}
        };
        assert(count_islands(grid) == 3);
    }

    {
        std::vector<std::vector<char>> grid = {
            {'1','1','1'},
            {'0','1','0'},
            {'1','1','1'}
        };
        assert(count_islands(grid) == 1);
    }

    return 0;
}