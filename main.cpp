#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include <thread>
#include <chrono>
using namespace std;

// Generates a number from 1 to 5
int generate_number() {
    random_device rand; // generates a seed from the os (hence random_device name)
    mt19937 gen(rand()); // no idea what this does
    uniform_int_distribution<> distrib(1,5); // Generates a number between 1 and 5. Since my grid is 6x6 (or 5 by 5 counting 0 indices) and has locations on the first row and column, the indexes I will be using for this project are 1 through 5, not 0 through 4.

    return distrib(gen);
}

class Board {
    private:
        string grid[6][6]; // 5x5 grid that each player uses.
        // As much as I wanted to avoid using getters/setters, I can't access the grid when its palced within the constructor, and I can't place the grid outside of the constructor for whatever reason.
        string name;

    public:

        //Constructor
        Board(string n) {
        name = n;
        string temporary_grid[6][6] = {
        // The actual grid/board that the game is played on. 
        // It is temporary, so that I can copy it into the actual grid (getter), and access the function outside the class.
        // ALSO, you said to use a 5 by 5 grid, but the coordinates on the readme range from 0-4. I used 1-5.
            //     1    2    3    4    5
            {" ", "1", "2", "3", "4", "5"},
            {"1", "~", "~", "~", "~", "~"},
            {"2", "~", "~", "~", "~", "~"},
            {"3", "~", "~", "~", "~", "~"},
            {"4", "~", "~", "~", "~", "~"},
            {"5", "~", "~", "~", "~", "~"}
        };
            // S - Ship
            // M - Miss
            // H - Hit
            // ~ - Water


        // COPIES TEMP GRID INTO MAIN GRID
        for (int i = 0; i < 6; ++i) {      // I for each row (6)
            for (int j = 0; j < 6; ++j) {  // J for each entry per row (also 6)
                grid[i][j] = temporary_grid[i][j];
                }
            }// END OF COPY FUNCTION - // I don't know if the syntax has always been this way, but this the first time I can recall putting a semicolon at the END of the declaration of a for loop..
        
        // CREATES 5 RANDOM SHIP LOCATIONS IN GRID
        int condition = 0;
        while (condition < 5) {
            int x = generate_number(), y = generate_number(); 
            if (grid[x][y] != "S") { // Ensures that the spot isn't taken
                grid[x][y] = "S"; // Reassigns the empty water (~) into a ship ("S")
                ++condition;
            }
        }
        
        }// END OF CONSTRUCTOR 


        // Draws the grid
        void draw_board() {
            cout << "* * * BATTLESHIP * * *" << endl;
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 6; ++j) {
                    if (grid[i][j] == "S") {
                        cout << "~ "; // Hides the location of ships during gameplay
                    } else {
                        cout << grid[i][j] << " ";
                    }
                }
                cout << endl;
            }
        }

        bool attack(int x, int y) {
        if (x < 1 || x > 5 || y < 1 || y > 5) {
            cout << "Invalid coordinates. Try again." << endl;
            return false;
        }

        if (grid[x][y] == "S") {
            cout << "Hit!" << endl;
            grid[x][y] = "H"; // Mark as hit
            return true;
        } else if (grid[x][y] == "~") {
            cout << "Miss!" << endl;
            grid[x][y] = "M"; // Mark as miss
        } else {
            cout << "Already attacked this location. Try again." << endl;
        }
        return false; // Returns false if either A, attack missed or B, location already hit.
        }
}; // END OF BOARD CLASS


void test()  {
}

// THE GAMEEEE (main function atleast)
int main() {
    int score = 0;
    int attack_count = 0;

    Board Computer("OpenAI");

    cout << "Battleships" << endl;
    
    // the actual game
    while (score < 5 && attack_count < 15) {
        int x, y;
        Computer.draw_board();

        // Takes a move from the player (ofc)
        cout << "Your move: " << endl;
        // cin >> x >> y;
        
        // Input Validation (GeeksForGeeks)
        if(!(cin >> x >> y)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid entry. Please enter a numeric value." << endl;
            continue;
        }

        if (Computer.attack(x,y) == true) {
            ++score;
        }

        ++attack_count;      
        cout << "Score: " << score << ", Attacks left: " << 15 - attack_count << endl;
    };

    if (score == 5) {
        cout << "You win! Congrats on sinking all the ships." << endl;
    } 
    
    cout << "Gamve over. Your score was: " << score << endl;
    
    return 0;
}

// Compile by typing:
// "g++ main.cpp -o playBattleship"

// Then run by typing
// "./playBattleship"



/* 
JOSHUA FASHE, B00883132.
SOURCES USED:

- https://www.youtube.com/watch?v=-NA_B_vJP14 (for generating random numbers)
- https://stackoverflow.com/questions/5590381/how-to-convert-int-to-string-in-c (converting int to string)
- https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library (Also for generating random numbers, except explains the <random> library)
- https://www.geeksforgeeks.org/how-to-add-timed-delay-in-cpp/
- https://www.tutorialspoint.com/cplusplus/cpp_declare_multiple_variables.htm#:~:text=How%20to%20Declare%20Multiple%20Variables,all%20variables%20to%20be%20declared.
- https://www.geeksforgeeks.org/how-to-validate-user-input-in-cpp/
- 
- 
*/
