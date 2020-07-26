#include <iostream>
#include <string>
using namespace std;

int main() {
    bool b;
    cout << "Give me a bool!\n";
    cin >> b;

    char c;
    cout << "Give me a character!\n";
    cin >> c;

    int i;
    cout << "Give me an integer!\n";
    cin >> i;

    double d = 7.89;
    cout << "Give me a double!\n";
    cin >> d;

    string s;
    cout << "Give me a string!\n";
    cin.get();
    getline(cin, s);

    cout << b << "\n";
    cout << c << "\n";
    cout << i << "\n";
    cout << d << "\n";
    cout << s << "\n";
    return 0;
}
