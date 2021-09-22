#include "PhoneBook.h"

PhoneBook::Person::Person(std::string surname, std::string name, std::optional<std::string> patronymic)
	: surname(surname), name(name), patronymic(patronymic)
{
}

bool PhoneBook::Person::operator<(const PhoneBook::Person& p)
{
	return std::tie(surname, name, patronymic) < std::tie(p.surname, p.name, p.patronymic);
}

bool PhoneBook::Person::operator>(const Person& p)
{
	return std::tie(surname, name, patronymic) > std::tie(p.surname, p.name, p.patronymic);
}

bool PhoneBook::Person::operator==(const Person& p)
{
	return std::tie(surname, name, patronymic) == std::tie(p.surname, p.name, p.patronymic);
}

//std::ostream& PhoneBook::Person::operator<<(std::ostream &out, const Person &person)
//{
//	out << std::internal << std::setw(10) << surname;
//	out << std::internal << std::setw(10) << name;
//	if (patronymic.has_value())
//		out << std::internal << std::setw(10) << patronymic.value();
//	out << std::endl;
//	return out;
//}

std::ostream& operator<<(std::ostream& out, const PhoneBook::Person &person)
{
	out << std::internal << std::setw(10) << person.surname;
	out << std::internal << std::setw(10) << person.name;
	if (person.patronymic.has_value())
		out << std::internal << std::setw(10) << person.patronymic.value();
	out << std::endl;
	return out;
}
