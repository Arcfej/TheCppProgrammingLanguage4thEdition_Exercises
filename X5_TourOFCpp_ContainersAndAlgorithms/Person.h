//
// Created by Arcfej on 26/08/2020.
//

#ifndef X5_TOUROFCPP_CONTAINERSANDALGORITHMS_PERSON_H
#define X5_TOUROFCPP_CONTAINERSANDALGORITHMS_PERSON_H
#include <string>
#include <iostream>

class Person {

private:
    std::string name;
    int age;
public:
    Person();
    Person(std::string &name, int &age);
    Person(const Person& person); // copy
    Person(Person&& person); // move

    Person &operator=(const Person& person); // copy
    Person &operator=(Person&& person);
    friend std::ostream &operator<<(std::ostream &os, const Person &person);
    friend std::istream &operator>>(std::istream &is, Person &person);

    virtual ~Person();
};


#endif //X5_TOUROFCPP_CONTAINERSANDALGORITHMS_PERSON_H
