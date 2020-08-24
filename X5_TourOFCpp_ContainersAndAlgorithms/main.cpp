#include <iostream>
#include <string>

using namespace std;

void getPerson();
void printPerson(string &name, int &age);
bool handleInputFail(istream &is);

int main() {
    while(true) {
        cin.clear();
        int menuOption;
        cout << "\nMenu:\n" << "---------------------------\n" <<
             "1) Input one person\n" <<
             "2) Exit\n";
        cin >> menuOption;
        cout << '\n';

        handleInputFail(cin);


        switch (menuOption) {
            case 1:
                getPerson();
                break;
            case 2:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Not a valid option. Please try again.\n";
        }
    }
}

void getPerson() {
    string name;
    int age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        cout << "What is your name?\n";
        getline(cin, name);
        if (!name.empty()) break;
        else cout << "Please enter a name\n";
    }

    while (true) {
        cout << "And your age?\n";
        cin >> age;
        if (!handleInputFail(cin)) break;
        else cout << "Not a valid age\n";
    }

    printPerson(name, age);
}

void printPerson(string &name, int &age) {
    cout << "Hello " << name << ", you're born " << age << " years ago.\n";
}

bool handleInputFail(istream &is) {
    // Handle input fails if there's any and return true if there was a fail.
    if (is.fail()) {
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    else return false;
}
