#include <iostream>
#include <string>
#include <vector>
#include "Person.h"

using namespace std;

void getPerson();
void getPeople();
void printPerson(string &name, int &age);
bool handleInputFail(istream &is);

int main() {
    while(true) {
        if (cin.gcount() > 0) cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int menuOption;
        cout << "\n" <<
                "Menu:\n" <<
                "---------------------------\n" <<
                "1) Input one person\n" <<
                "2) Input multiple people\n" <<
                "3) Exit\n";
        cin >> menuOption;
        cout << '\n';

        handleInputFail(cin);

        switch (menuOption) {
            case 1:
                getPerson();
                break;
            case 2:
                getPeople();
                break;
            case 3:
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

void getPeople() {
    bool read = true;
    vector<Person> people;
    while (read) {
        Person person;
        cout << "Please enter a person's name and age like this: John Doe,45.\nDon't use a space after the column!\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> person;
        if (!handleInputFail(cin)) {
            people.push_back(person);
        } else {
            cout << "Not a valid input.\n";
        }
        cout << "Would you like to enter another person? (y/n)\n";
        char c;
        cin >> c;
        read = c == 'y';
    }

    for (const auto& person : people) {
        cout << person;
    }
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
