#include "PhoneBook.h"

PhoneBook::Person::Person(std::string surname, std::string name, std::optional<std::string> patronymic)
	: surname(surname), name(name), patronymic(patronymic)
{
}

bool PhoneBook::Person::operator<(const PhoneBook::Person& p)
{
	return std::tie(surname, name, patronymic) < std::tie(p.surname, p.name, p.patronymic);
}
