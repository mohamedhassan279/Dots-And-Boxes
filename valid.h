#ifndef VALID_H_INCLUDED
#define VALID_H_INCLUDED

// check if the move is valid using 4 functions
// first function to check if the points in borders of the grid
bool inside_grid(int x1, int y1, int x2, int y2, int n, char grid[3 *n + 2][5 *n + 3])
{
    if (x1 > 0 && x1 < (n + 2) && y1 > 0 && y1 < (n + 2) && x2 > 0 && x2 < (n + 2) && y2 > 0 && y2 < (n + 2))
        return true;
    return false;
}

// second function to check adjacent points
bool adj(int x1, int y1, int x2, int y2, int n, char grid[3 *n + 2][5 *n + 3])
{
    if (x1 == x2 && abs(y1 - y2) == 1)
        return true;
    if (y1 == y2 && abs(x1 - x2) == 1)
        return true;
    return false;
}

// third function to check if this move is already made
bool existing_move(int x1, int y1, int x2, int y2, int n, char grid[3 *n + 2][5 *n + 3])
{
    int r1 = 3 *x1 - 2, r2 = 3 *x2 - 2, c1 = 5 *y1 - 3, c2 = 5 *y2 - 3;	//get the index of points in the array
    char h = 196, v = 179;	// h for horizontal line and v for vertical line

    if (r1 == r2 && c1 < c2 && (grid[r1][c1 + 1] == h || grid[r1][c1 + 1] == 'a' || grid[r1][c1 + 1] == 'b'))
        return true;
    if (r1 == r2 && c1 > c2 && (grid[r1][c2 + 1] == h || grid[r1][c2 + 1] == 'a' || grid[r1][c2 + 1] == 'b'))
        return true;
    if (c1 == c2 && r1 < r2 && (grid[r1 + 1][c1] == v || grid[r1 + 1][c1] == 'a' || grid[r1 + 1][c1] == 'b'))
        return true;
    if (c1 == c2 && r1 > r2 && (grid[r2 + 1][c1] == v || grid[r2 + 1][c1] == 'a' || grid[r2 + 1][c1] == 'b'))
        return true;
    return false;
}

// the valid move function
bool valid_move(int x1, int y1, int x2, int y2, int n, char grid[3 *n + 2][5 *n + 3])
{
    // inputs for main menu, save, undo, redo
    if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
        return true;
    if (x1 == 1 && x2 == 1 && y1 == 1 && y2 == 1)
        return true;
    if (x1 == 2 && x2 == 2 && y1 == 2 && y2 == 2)
        return true;
    if (x1 == 3 && x2 == 3 && y1 == 3 && y2 == 3)
        return true;
    // valid move: the two points should be adjacent and inside the borders of grid and the move was not made before
    if (inside_grid(x1, y1, x2, y2, n, grid) && adj(x1, y1, x2, y2, n, grid) && !existing_move(x1, y1, x2, y2, n, grid))
        return true;
    return false;
}

#endif // VALID_H_INCLUDED
