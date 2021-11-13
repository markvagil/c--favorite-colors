#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
// imports and setting namespace

class Main {
  public:
    // creating the vector which will store colors and its iterator
    vector<string> colors;
    vector<string>::iterator it;
    // creating some basic int variables
    int a;
    int x;

    void main() {
      // This is the main function that runs the program continously and calls other functions to process each action
      colors.reserve(99); // This line makes the vector capable of holding 99 items inside of it
      cout << "" << "\n" ;
      cout << "Please enter an action you would like to perform!" << "\n";
      cout << "" << "\n" ;
      cout << "[1] - View the current list" << "\n";
      cout << "[2] - Add a color to the list" << "\n";
      cout << "[3] - Remove a color from the list" << "\n";
      cout << "[4] - Save the list to computer" << "\n";
      cout << "[5] - Read the list from computer" << "\n";
      cout << "[6] - Quit program\n" << "\n";

      a = get_input(6); // function that gets the input of the user and returns it, user can enter a number 1 through 6

      if (a == 1) {
        cout << "PRINTING LIST\n";
        print_list(); // This function will print the all of the items inside the vector
      } else if (a == 2) {
        cout << "ADDING COLOR\n";
        add_color(); // This function will allow you to add a new color to the vector
      } else if (a == 3) {
        cout << "REMOVING COLOR\n";
        remove_color(); // This function will allow the user to remove a color from the vector
      } else if (a == 4) {
        cout << "SAVING LIST\n";
        save_list(); // This function will save the list as a text file to the computer
      } else if (a == 5) {
        cout << "READING LIST\n";
        read_list(); // This function will read the text file back into the vector on top of the existing elements
      } else if (a == 6) {
        // 6
        // quits program
        cout << "~~~PROGRAM ENDED~~~";
        exit(0);
      }

      main(); // calls the main function again after whatever action has been performed
    }

    int get_input(int max_input) {
      // This function gets the input from the user up to a certain number (max_input), validates it, and returns that input
      cout << "Please enter a valid input:" << "\n";
      cin >> a;
      while(1) {
        if(cin.fail()) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout<<"You have entered an invalid integer."<<endl;
          cin>>a;
        }
        if(!cin.fail()) {
          if(a >= 1 && a <= max_input) {
            break;
          } else {
            cin.clear();
            cout<<"You have entered an invalid integer outside the available options."<<endl;
            cin>>a;
          }
        }  
      }

      cout << "The input was: " << a <<endl;
      cout << "\n";
      return a;
    }

    void print_list() {
      // 1
      // prints the list of colors from the vector
      int i;
      for (i = 0; i < colors.size(); i++)
        cout << i+1 << " - " << colors[i] << "\n";
    }

    void add_color() {
      // 2
      // adds a new color to the vector
      string new_color;
      cout << "Please enter the name of a color:\n";
      getline(cin, new_color);
      getline(cin, new_color);
      colors.push_back(new_color);
    }

    void remove_color() {
      // 3
      // removes a color from the vector based on index
      if (colors.size() == 0) {
        cout << "List is empty.\n";
      } else {
        cout << "Please enter a number 1 through " << colors.size() << " of the color you would like to remove from the list.\n";
        x = get_input(colors.size());
        x--;
        it = colors.begin() + x;
        colors.erase(it);
      }
    }

    void save_list() {
      // 4
      // saves the vector to the computer as a .txt file
      ofstream outFile("favorite_colors.txt");
      // the important part
      for (const auto &e : colors) outFile << e << "\n";
    }

    void read_list() {
      // 5
      // reads the saved list (.txt file) from the computer
      ifstream file_in("favorite_colors.txt");
      string line;

      while(getline(file_in, line))
      {
        string new_line;
        new_line = line;
        cout<<new_line;
        colors.push_back(new_line);
      }
    }
};

int main() {
  // runs when you start the program and initializes the main class as "program" and calls main() from "program" to start it
  Main program;
  cout << "Welcome to the favorite color tracker!" << "\n";
  program.main();
  return 0;
}
