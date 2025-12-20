#include "s.h"
#include <iostream>

int main() {
    
    int grades1[] = {5, 4, 5, 4};
    int grades2[] = {4, 5, 4, 5, 5};
  
    StudentAfterSecond s3("Dmitrieva", 1, 102, 12070, grades1, grades2);
    
 
    
    std::cout << "Student 1 " << std::endl;
    std::cout << s3 << std::endl;
    std::cout << "Yearly average: " << s3.average() << std::endl << std::endl;
    
    // Изменение оценок
    s3.setGrade(0, 3);
    std::cout << "After changing grade: " << s3.getGrade(0) << std::endl;
    std::cout << "New average: " << s3.average() << std::endl << std::endl;
    
    // Массив указателей
    const int SIZE = 5;
    Student* students[SIZE];
    
    int g1[] = {4,4,4,4};
    int g2[] = {5,5,5,5};
    int g3[] = {3,4,3,4,3};
    
    students[0] = new Student("Lolo", 1, 101, 12348);
    students[1] = new StudentAfterFirst("Borisov", 1, 101, 12349, g1);
    students[2] = new StudentAfterSecond("Patapchik", 1, 102, 12350, g1, g2);
    students[3] = new StudentAfterFirst("Abushkevich", 1, 102, 12351, g2);
    students[4] = new StudentAfterSecond("Ivaniv", 2, 201, 12352, g2, g3);
    
    // Статистика
    std::cout << "=== Statistics ===" << std::endl;
    std::cout << "Group 101 average after first session: " 
              << groupAverageFirst(students, SIZE, 101) << std::endl;
    std::cout << "Group 102 average after second session: " 
              << groupAverageSecond(students, SIZE, 102) << std::endl;
    std::cout << "Array average: " << arrayAverage(students, SIZE) << std::endl;
    
    // Очистка
    for(int i = 0; i < SIZE; i++) {
        delete students[i];
    }
    
    return 0;
}