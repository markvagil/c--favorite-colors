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
    vector<string> colors;
    vector<string>::iterator it;
    int a;
    int x;

    void main() {
      colors.reserve(99);
      cout << "" << "\n" ;
      cout << "Please enter an action you would like to perform!" << "\n";
      cout << "" << "\n" ;
      cout << "[1] - View the current list" << "\n";
      cout << "[2] - Add a color to the list" << "\n";
      cout << "[3] - Remove a color from the list" << "\n";
      cout << "[4] - Save the list to computer" << "\n";
      cout << "[5] - Read the list from computer" << "\n";
      cout << "[6] - Quit program\n" << "\n";

      a = get_input(6);

      if (a == 1) {
        cout << "PRINTING LIST\n";
        print_list();
      } else if (a == 2) {
        cout << "ADDING COLOR\n";
        add_color();
      } else if (a == 3) {
        cout << "REMOVING COLOR\n";
        remove_color();
      } else if (a == 4) {
        cout << "SAVING LIST\n";
        save_list();
      } else if (a == 5) {
        cout << "READING LIST\n";
        read_list();
      } else if (a == 6) {
        // 6
        // quits program
        cout << "~~~PROGRAM ENDED~~~";
        exit(0);
      }

      main();
    }

    int get_input(int max_input) {
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
      if (colors.size() == 0) {
        cout << "The list is empty.\n";
      } else {
        for (i = 0; i < colors.size(); i++)
        cout << i+1 << " - " << colors[i] << "\n";
      }
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
        cout<<new_line<<"\n";
        colors.push_back(new_line);
      }
    }
};

int main() {
  Main program;
  cout << "Welcome to the favorite color tracker!" << "\n";
  program.main();
  return 0;
}
