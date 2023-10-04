#include <iostream>
#include <cstdio> // For getchar() function

using namespace std;

const int MAZE_SIZE = 5;

// Define the maze using a 2D array (empty maze)
char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'S', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', 'E'},
    {' ', ' ', ' ', ' ', ' '},
};

int playerX = 0;
int playerY = 0;
bool hasWon = false;

// Function to print the maze with the player's position
void printMaze() {
    system("clear"); // Clear the console (for Unix-based systems, use "cls" for Windows)
    cout << "Maze (Use 'W', 'S', 'A', 'D' to move, 'Q' to quit):" << endl;

    for (int i = 0; i < MAZE_SIZE; ++i) {
        for (int j = 0; j < MAZE_SIZE; ++j) {
            char cell = maze[i][j];
            if (i == playerX && j == playerY) {
                cout << "P "; // Display the player
            } else {
                cout << cell << ' '; // Display the maze cell
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to move the player
void movePlayer(char direction) {
    if (hasWon) {
        return; // If the player has won, no further moves are allowed
    }

    int newX = playerX;
    int newY = playerY;

    switch (direction) {
        case 'W':
            newX--;
            break;
        case 'S':
            newX++;
            break;
        case 'A':
            newY--;
            break;
        case 'D':
            newY++;
            break;
    }

    // Check if the new position is valid
    if (newX >= 0 && newX < MAZE_SIZE && newY >= 0 && newY < MAZE_SIZE) {
        // Move the player
        playerX = newX;
        playerY = newY;

        // Check if the player has reached the exit
        if (maze[playerX][playerY] == 'E') {
            hasWon = true;
        }
    }
}

int main() {
    cout << "Welcome to the Interactive Maze Game!" << endl;
    cout << "Objective: Reach the exit 'E' to win." << endl;

    while (true) {
        printMaze();
        char move = getchar(); // Use getchar() to get a character

        if (move == 'Q' || move == 'q') {
            cout << "Game over. Thanks for playing!" << endl;
            break;
        }

        movePlayer(move);

        if (hasWon) {
            printMaze();
            cout << "You won!" << endl;
            break;
        }
    }

    return 0;
}
