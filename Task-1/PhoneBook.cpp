#include "PhoneBook.h"
#include <sstream>
#include <algorithm>

bool PhoneBook::Person::operator<(const Person& p)
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

std::ostream& operator<<(std::ostream& out, const PhoneBook book)
{
	for (auto contact : book.contacts)
	{
		out << contact.first << " " << contact.second << std::endl;
	}
	return out;
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

//bool PhoneBook::compNames(std::pair<Person, PhoneNumber> &firstContact, const std::pair<Person, PhoneNumber> &secondContact)
//{
//	return (firstContact.first < secondContact.first);
//}
//
//bool PhoneBook::compPhones(const std::pair<Person, PhoneNumber>& firstContact, const std::pair<Person, PhoneNumber>& secondContact)
//{
//	return (firstContact.second < secondContact.second);
//}

//bool PhoneBook::findPerson(const std::pair<Person, PhoneNumber>& contact)
//{
//	return false;
//}

//void PhoneBook::sortByName()
//{
//	std::cout << "----- Sort by name -----" << std::endl;
//	std::sort(contacts.begin(), contacts.end(), compNames);
//}

void PhoneBook::sortByName()
{
	std::cout << "----- Sort by name -----" << std::endl;
	std::sort(contacts.begin(), contacts.end(), [](std::pair<PhoneBook::Person, PhoneBook::PhoneNumber> firstContact, std::pair<PhoneBook::Person, PhoneBook::PhoneNumber> secondContact)
		{
			return firstContact.first < secondContact.first;
		});
}

//void PhoneBook::sortByPhone()
//{
//	std::cout << "----- Sort by phone -----" << std::endl;
//	std::sort(contacts.begin(), contacts.end(), compPhones);
//}

void PhoneBook::sortByPhone()
{
	std::cout << "----- Sort by phone -----" << std::endl;
	std::sort(contacts.begin(), contacts.end(), [](std::pair<PhoneBook::Person, PhoneBook::PhoneNumber> firstContact, std::pair<PhoneBook::Person, PhoneBook::PhoneNumber> secondContact)
		{
			return firstContact.second < secondContact.second;
		});
}

void PhoneBook::changePhoneNumber(std::string surname, std::string name, std::optional<std::string> patronimic, int countryId, int cityID, std::string number, std::optional<int> extension)
{
	Person person(surname, name, patronimic);
	PhoneNumber phoneNumber(countryId, cityID, number, extension);
	std::cout << "----- Change phone number -----" << std::endl;
	std::_Vector_const_iterator iter = contacts.begin();
	auto targetPerson = std::find_if(contacts.begin(), contacts.end(), [person](std::pair<PhoneBook::Person, PhoneBook::PhoneNumber> contact)
		{
			return contact.first == person;
		});
	if (targetPerson == contacts.end())
		return;
	targetPerson->second = phoneNumber;
}

//void PhoneBook::changePhoneNumber(Person& person, PhoneNumber& phoneNumber)
//{
//	std::cout << "----- Change phone number -----" << std::endl;
//	std::_Vector_const_iterator iter = contacts.begin();
//	auto targetPerson = std::find_if(contacts.begin(), contacts.end(), findPerson);
//	
//}

//void PhoneBook::changePhoneNumber(Person& person, PhoneNumber& phoneNumber)
//{
//	std::cout << "----- Change phone number -----" << std::endl;
//	std::_Vector_const_iterator iter = contacts.begin();
//	auto targetPerson = std::find_if(contacts.begin(), contacts.end(), [person](std::pair<PhoneBook::Person, PhoneBook::PhoneNumber> contact)
//		{
//			return contact.first == person;
//		});
//	if (targetPerson == contacts.end())
//		return;
//	targetPerson->second = phoneNumber;
//}