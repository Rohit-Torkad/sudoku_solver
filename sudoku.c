#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to print the current state of the puzzle
void print_puzzle(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a given cell
bool is_valid(int puzzle[N][N], int row, int col, int num) {
    // Check row
    for (int j = 0; j < N; j++) {
        if (puzzle[row][j] == num) {
            return false;
        }
    }
    // Check column
    for (int i = 0; i < N; i++) {
        if (puzzle[i][col] == num) {
            return false;
        }
    }
    // Check sub-grid
    int sub_grid_row = (row / 3) * 3;
    int sub_grid_col = (col / 3) * 3;
    for (int i = sub_grid_row; i < sub_grid_row + 3; i++) {
        for (int j = sub_grid_col; j < sub_grid_col + 3; j++) {
            if (puzzle[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to find the next empty cell
bool find_empty_cell(int puzzle[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (puzzle[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the puzzle using backtracking
bool solve(int puzzle[N][N]) {
    int row, col;
    if (!find_empty_cell(puzzle, &row, &col)) {
        return true; // Puzzle solved!
    }
    for (int num = 1; num <= 9; num++) {
        if (is_valid(puzzle, row, col, num)) {
            puzzle[row][col] = num;
            if (solve(puzzle)) {
                return true;
            }
            puzzle[row][col] = 0;
        }
    }
    return false; // Puzzle unsolvable
}


void solve(char puzzle[9][9]) {
  // TODO: Implement the Sudoku solver algorithm
}

int main(int argc, char* argv[]) {
  char puzzle[9][9];

  // Parse the puzzle from the command-line argument
  // ...

  solve(puzzle);

  // Print the solved puzzle to stdout
  // ...
}

// int main() {
//     int puzzle[N][N] = {
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0}
//     };

//     printf("Welcome to Sudoku!\n");
//     printf("Enter numbers from 1 to 9 to fill in the puzzle.\n");
//     printf("Use 0 to clear a cell.\n");
//     printf("Press enter after each number.\n");
//     printf("Enter the puzzle row by row, left to right.\n");
//     printf("For example, to enter the first row of the example puzzle, enter: 530070000\n\n");

//     // Input puzzle
//     printf("Enter the puzzle:\n");
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             int val;
//             scanf("%1d", &val); // Read one digit at a time
//             puzzle[i][j] = val;
//         }
//     }

//     // Print initial puzzle
//     printf("\nInitial puzzle:\n");
//     print_puzzle(puzzle);

//     // Solve puzzle
//     printf("\nSolving puzzle...\n");
//     if (solve(puzzle)) {
//         printf("\nSolution found:\n");
//         print_puzzle(puzzle);
//     } else {
//         printf("\nNo solution found.\n");
//     }

//     return 0;
// }

