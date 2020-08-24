#include <iostream>
#include <string>

using namespace std;

void getPerson();
void printPerson(string &name, int &age);

int main() {
    cout << "Hello, World!\n";

    getPerson();

    return 0;
}

void getPerson() {
    string name;
    int age;

    cout << "What is your name?\n";
    getline(cin, name);

    cout << "And your age?\n";
    cin >> age;

    printPerson(name, age);
}

void printPerson(string &name, int &age) {
    cout << "Hello " << name << ", you're born " << age << " years ago.\n";
}
