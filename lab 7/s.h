#ifndef S_H
#define S_H

#include <iostream>

class Student {
protected:
    static int next_id;
    const int id;
    char* name;
    int course;
    int group;
    const int record_book;
    
public:
    Student(const char* n, int c, int g, int rb);
    Student(const Student& other);
    virtual ~Student();
    
    // Запрет конструктора без параметров
    Student() = delete;
    
    // Set- и get-методы
    void setName(const char* n);
    const char* getName() const { return name; }
    
    void setCourse(int c) { course = c; }
    int getCourse() const { return course; }
    
    void setGroup(int g) { group = g; }
    int getGroup() const { return group; }
    
    int getId() const { return id; }
    int getRecordBook() const { return record_book; }
    
    // Виртуальный метод вывода
    virtual void print(std::ostream& os) const;
    
    // Полиморфный метод среднего балла
    virtual float average() const { return 0.0f; }
    
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

class StudentAfterFirst : public Student {
protected:
    int grades[4];
    
public:
    StudentAfterFirst(const char* n, int c, int g, int rb, const int gr[4]);
    StudentAfterFirst(const StudentAfterFirst& other);
    
    // Доступ к оценкам
    int getGrade(int index) const;
    void setGrade(int index, int value);
    
    void print(std::ostream& os) const override;
    float average() const override;
};

class StudentAfterSecond : public StudentAfterFirst {
private:
    int grades2[5];
    
public:
    StudentAfterSecond(const char* n, int c, int g, int rb, 
                       const int gr1[4], const int gr2[5]);
    StudentAfterSecond(const StudentAfterSecond& other);
    
    // Доступ к оценкам второй сессии
    int getGrade2(int index) const;
    void setGrade2(int index, int value);
    
    void print(std::ostream& os) const override;
    float average() const override;
    
    // Средний за год
    float yearlyAverage() const;
};

// Функции для статистики
float groupAverageFirst(Student** students, int size, int group);
float groupAverageSecond(Student** students, int size, int group);
float arrayAverage(Student** students, int size);

#endif