#include "PhoneBook.h"
#include <sstream>

PhoneBook::Person::Person()
	:patronymic(std::nullopt)
{
}

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
	out << std::internal << std::setw(16) << person.surname;
	out << std::internal << std::setw(12) << person.name;
	if (person.patronymic.has_value())
		out << std::internal << std::setw(16) << person.patronymic.value();
	else
		out << std::internal << std::setw(16) << "";
	return out;
}

std::istream& operator>>(std::istream& in, PhoneBook::Person& person)
{
	in >> person.surname;
	in >> person.name;
	std::string patronimicString;
	in >> patronimicString;
	if (patronimicString == "-")
	{
		person.patronymic = std::nullopt;
	}
	else
	{
		person.patronymic = patronimicString;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const PhoneBook::PhoneNumber& phoneNumber)
{
	out << "+" << phoneNumber.countryId << "(" << phoneNumber.cityId << ")"
		<< phoneNumber.number;
	if (phoneNumber.extension.has_value())
		out << "  " << phoneNumber.extension.value();
	return out;
}

std::istream& operator>>(std::istream& in, PhoneBook::PhoneNumber& phoneNumber)
{
	in >> phoneNumber.countryId;
	in >> phoneNumber.cityId;
	in >> phoneNumber.number;
	std::string extensionString;
	in >> extensionString;
	if (extensionString == "-")
	{
		phoneNumber.extension = std::nullopt;
	}
	else
	{
		std::stringstream sStream;
		sStream << extensionString;
		int extInt;
		sStream >> extInt;
		phoneNumber.extension = extInt;

	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const PhoneBook book)
{
	for (auto contact : book.contacts)
	{
		out << contact.first << " " << contact.second << std::endl;
	}
	return out;
}

PhoneBook::PhoneNumber::PhoneNumber()
	:countryId(0), cityId(0)
{
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

PhoneBook::PhoneBook(std::ifstream& file)
{
	if (!file.is_open())
	{
		std::cout << "Can't open file." << std::endl;
		return;
	}
	
	while (!file.eof())
	{
		std::string inputLine;
		std::getline(file, inputLine);
		std::stringstream inputStream;
		inputStream << inputLine;
		auto contact = std::make_pair(Person(), PhoneNumber());
		inputStream >> contact.first >> contact.second;
		contacts.push_back(contact);
	}
}
