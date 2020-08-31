//
// Created by Arcfej on 26/08/2020.
//

#include "Person.h"

#include <utility>

Person::Person() {name = ""; age = -1;}

Person::Person(std::string &name, int &age) : name(name), age(age) {}

Person::Person(const Person& person) : name(person.name), age(person.age) {}

Person::Person(Person&& person) : name(person.name), age(person.age) {}

Person &Person::operator=(const Person& person) {
    name = person.name;
    age = person.age;
    return *this;
}

Person &Person::operator=(Person&& person) {
    name = person.name;
    age = person.age;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Person &person) {
    return os << "Hello " << person.name << ", you're born " << person.age << " years ago.\n";
}

std::istream &operator>>(std::istream &is, Person &person) {
    std::string name;
    int age;

    if (is.gcount() > 0) is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    char c;
    while (is >> c && c != ',') {
        name += c;
    }

    is >> age;

    person = Person(name, age);
    return is;
}

Person::~Person() = default;
