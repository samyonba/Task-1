#include <iostream>
#include "PhoneBook.h"

int main()
{
    std::ifstream file("C:\\Users\\1\\Desktop\\C++ сложные моменты\\Projects\\Task-1\\Task-1\\Input.txt");
    std::cout << "----- PhoneBook -----" << std::endl;
    PhoneBook phoneBook(file);

    std::cout << phoneBook << std::endl;

    phoneBook.sortByName();
    std::cout << phoneBook << std::endl;

    phoneBook.sortByPhone();
    std::cout << phoneBook << std::endl;

    std::cout << "----- ChangePhoneNumber -----" << std::endl;
    phoneBook.changePhoneNumber("Kotov", "Vasilii", "Eliseevich", 7, 123, "15344458", std::nullopt);
    phoneBook.changePhoneNumber("Mironova", "Margarita", "Vladimirovna", 16, 465, "9155448", 13);
    std::cout << phoneBook << std::endl;
    
    file.close();
}
