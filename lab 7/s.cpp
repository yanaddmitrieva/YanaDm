#include "s.h"
#include <cstring>
#include <stdexcept>

int Student::next_id = 1;

// Реализация Student
Student::Student(const char* n, int c, int g, int rb) : 
    id(next_id++), course(c), group(g), record_book(rb) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

Student::Student(const Student& other) : 
    id(next_id++), course(other.course), group(other.group), 
    record_book(other.record_book) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

Student::~Student() {
    delete[] name;
}

void Student::setName(const char* n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Student::print(std::ostream& os) const {
    os << "ID: " << id << "\nName: " << name 
       << "\nCourse: " << course << "\nGroup: " << group 
       << "\nRecord book: " << record_book;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    s.print(os);
    return os;
}

// Реализация StudentAfterFirst
StudentAfterFirst::StudentAfterFirst(const char* n, int c, int g, int rb, 
                                     const int gr[4]) : 
    Student(n, c, g, rb) {
    for(int i = 0; i < 4; i++) {
        grades[i] = gr[i];
    }
}

StudentAfterFirst::StudentAfterFirst(const StudentAfterFirst& other) : 
    Student(other) {
    for(int i = 0; i < 4; i++) {
        grades[i] = other.grades[i];
    }
}

int StudentAfterFirst::getGrade(int index) const {
    if(index < 0 || index >= 4) 
        throw std::out_of_range("Invalid grade index");
    return grades[index];
}

void StudentAfterFirst::setGrade(int index, int value) {
    if(index < 0 || index >= 4) 
        throw std::out_of_range("Invalid grade index");
    grades[index] = value;
}

void StudentAfterFirst::print(std::ostream& os) const {
    Student::print(os);
    os << "\nFirst session grades: ";
    for(int i = 0; i < 4; i++) {
        os << grades[i] << " ";
    }
}

float StudentAfterFirst::average() const {
    float sum = 0;
    for(int i = 0; i < 4; i++) {
        sum += grades[i];
    }
    return sum / 4.0f;
}

// Реализация StudentAfterSecond
StudentAfterSecond::StudentAfterSecond(const char* n, int c, int g, int rb,
                                       const int gr1[4], const int gr2[5]) : 
    StudentAfterFirst(n, c, g, rb, gr1) {
    for(int i = 0; i < 5; i++) {
        grades2[i] = gr2[i];
    }
}

StudentAfterSecond::StudentAfterSecond(const StudentAfterSecond& other) : 
    StudentAfterFirst(other) {
    for(int i = 0; i < 5; i++) {
        grades2[i] = other.grades2[i];
    }
}

int StudentAfterSecond::getGrade2(int index) const {
    if(index < 0 || index >= 5) 
        throw std::out_of_range("Invalid grade index");
    return grades2[index];
}

void StudentAfterSecond::setGrade2(int index, int value) {
    if(index < 0 || index >= 5) 
        throw std::out_of_range("Invalid grade index");
    grades2[index] = value;
}

void StudentAfterSecond::print(std::ostream& os) const {
    StudentAfterFirst::print(os);
    os << "\nSecond session grades: ";
    for(int i = 0; i < 5; i++) {
        os << grades2[i] << " ";
    }
}

float StudentAfterSecond::average() const {
    return yearlyAverage();
}

float StudentAfterSecond::yearlyAverage() const {
    float sum = 0;
    for(int i = 0; i < 4; i++) {
        sum += grades[i];
    }
    for(int i = 0; i < 5; i++) {
        sum += grades2[i];
    }
    return sum / 9.0f;
}

// Функции для статистики
float groupAverageFirst(Student** students, int size, int group) {
    float sum = 0;
    int count = 0;
    
    for(int i = 0; i < size; i++) {
        StudentAfterFirst* s = dynamic_cast<StudentAfterFirst*>(students[i]);
        if(s && s->getGroup() == group) {
            sum += s->average();
            count++;
        }
    }
    
    return count > 0 ? sum / count : 0.0f;
}

float groupAverageSecond(Student** students, int size, int group) {
    float sum = 0;
    int count = 0;
    
    for(int i = 0; i < size; i++) {
        StudentAfterSecond* s = dynamic_cast<StudentAfterSecond*>(students[i]);
        if(s && s->getGroup() == group) {
            sum += s->average();
            count++;
        }
    }
    
    return count > 0 ? sum / count : 0.0f;
}

float arrayAverage(Student** students, int size) {
    float sum = 0;
    int count = 0;
    
    for(int i = 0; i < size; i++) {
        if(students[i]) {
            sum += students[i]->average();
            count++;
        }
    }
    
    return count > 0 ? sum / count : 0.0f;
}