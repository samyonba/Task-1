#include <iostream>
#include "PhoneBook.h"

int main()
{
    std::ifstream file("C:\\Users\\1\\Desktop\\C++ сложные моменты\\Projects\\Task-1\\Task-1\\Input.txt");
    PhoneBook phoneBook(file); // Создание и инициализация телефонной книжки


    std::cout << "----- PhoneBook -----" << std::endl;
    std::cout << phoneBook << std::endl; // Печать исходного состояния


    phoneBook.sortByName();
    std::cout << phoneBook << std::endl; // Печать после сортировки по имени


    phoneBook.sortByPhone();
    std::cout << phoneBook << std::endl; // Печать после сортировки по номеру телефона


    std::cout << "----- ChangePhoneNumber -----" << std::endl;
    phoneBook.changePhoneNumber("Kotov", "Vasilii", "Eliseevich", 7, 123, "15344458", std::nullopt);
    phoneBook.changePhoneNumber("Mironova", "Margarita", "Vladimirovna", 16, 465, "9155448", 13);
    std::cout << phoneBook << std::endl; // Печать после изменения номеров телефонов у некоторых контактов

    
    std::string surnameToGetNumber = "Ilin"; // для поиска по другой фамилии достаточно изменить переменную surnameToGetNumber
    std::cout << "----- GetPhoneNumber -----" << std::endl;
    if (phoneBook.getPhoneNumber(surnameToGetNumber).first != "not found" && phoneBook.getPhoneNumber(surnameToGetNumber).first != "found more than one")
    {
        std::cout << " " << std::internal << std::setw(16) << std::left << phoneBook.getPhoneNumber(surnameToGetNumber).first << " " << phoneBook.getPhoneNumber(surnameToGetNumber).second << std::endl;
    }
    else
    {
        std::cout << " " << std::internal << std::setw(16) << std::left << phoneBook.getPhoneNumber(surnameToGetNumber).first << std::endl;
    } // Вывод результатов поиска по фамилии

    
    file.close();
}
