#include "PhoneBook.h"

PhoneBook::Person::Person(std::string surname, std::string name)
	: surname(surname), name(name), patronymic(std::nullopt)
{
}

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

std::ostream& operator<<(std::ostream& out, const PhoneBook::Person& person)
{
	out << std::internal << std::setw(10) << person.surname;
	out << std::internal << std::setw(10) << person.name;
	if (person.patronymic.has_value())
		out << std::internal << std::setw(10) << person.patronymic.value();
	return out;
}

std::ostream& operator<<(std::ostream& out, const PhoneBook::PhoneNumber& phoneNumber)
{
	out << "+" << phoneNumber.countryId << "(" << phoneNumber.cityId << ")"
		<< phoneNumber.number;
	if (phoneNumber.extension.has_value())
		out << " " << phoneNumber.extension.value();
	return out;
}

PhoneBook::PhoneNumber::PhoneNumber(int countryId, int cityId, std::string number)
	: countryId(countryId), cityId(cityId), number(number), extension(std::nullopt)
{
}

PhoneBook::PhoneNumber::PhoneNumber(int countryId, int cityId, std::string number, std::optional<int> extension)
	: countryId(countryId), cityId(cityId), number(number), extension(extension)
{
}

bool PhoneBook::PhoneNumber::operator<(const PhoneNumber& phone)
{
	return std::tie(this->countryId, cityId, number, extension)<std::tie(phone.countryId, phone.cityId, phone.number, phone.extension);
}

bool PhoneBook::PhoneNumber::operator>(const PhoneNumber& phone)
{
	return std::tie(this->countryId, cityId, number, extension) > std::tie(phone.countryId, phone.cityId, phone.number, phone.extension);
}

bool PhoneBook::PhoneNumber::operator==(const PhoneNumber& phone)
{
	return std::tie(this->countryId, cityId, number, extension) == std::tie(phone.countryId, phone.cityId, phone.number, phone.extension);
}
