class Solution {
  public:
    // Directions for moving in 8 directions (horizontal, vertical, and diagonal)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    // Function to perform DFS to visit all connected land ('1')
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m) {
        // Mark the current cell as visited
        visited[i][j] = true;

        // Explore all 8 possible directions
        for (auto dir : directions) {
            int newX = i + dir.first;
            int newY = j + dir.second;

            // Check if the new coordinates are within bounds and not yet visited
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1' && !visited[newX][newY]) {
                dfs(newX, newY, grid, visited, n, m);
            }
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns
        
        // Visited matrix to track cells we've already processed
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islandCount = 0; // This will store the number of islands

        // Traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is land ('1') and not yet visited, it marks the start of a new island
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islandCount++;
                    dfs(i, j, grid, visited, n, m); // Perform DFS to mark the entire island as visited
                }
            }
        }

        return islandCount; // Return the total number of islands found
    }
};
