// Task-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "PhoneBook.h"

int main()
{
    std::ifstream file("C:\\Users\\1\\Desktop\\C++ сложные моменты\\Projects\\Task-1\\Task-1\\Input.txt");
    //file.open("Input.txt");
    PhoneBook phoneBook(file);
    std::cout << phoneBook << std::endl;
    file.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"