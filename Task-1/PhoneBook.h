#pragma once
#include <iostream>
#include <string>
#include <optional>
#include <functional>
#include <iomanip>
#include <fstream>
class PhoneBook
{
//public:
private:
	struct Person
	{
	private:
		std::string surname;
		std::string name;
		std::optional<std::string> patronymic;
	
	public:
		Person();
		Person(std::string surname, std::string name);
		Person(std::string surname, std::string name, std::optional<std::string> patronymic);
		bool operator<(const Person &p);
		bool operator>(const Person& p);
		bool operator==(const Person& p);
		friend std::ostream& operator<<(std::ostream &out, const Person &person);
		friend std::istream& operator>>(std::istream& in, Person& person);
	};

	friend std::ostream& operator<<(std::ostream &out, const Person &person);
	friend std::istream& operator>>(std::istream& in, Person& person);

	struct PhoneNumber
	{
	private:
		int countryId;
		int cityId;
		std::string number;
		std::optional<int> extension;
	public:
		PhoneNumber();
		PhoneNumber(int countryId, int cityId, std::string number);
		PhoneNumber(int countryId, int cityId, std::string number, std::optional<int> extension);
		bool operator<(const PhoneNumber& phone);
		bool operator>(const PhoneNumber& phone);
		bool operator==(const PhoneNumber& phone);
		friend std::ostream& operator<<(std::ostream& out, const PhoneNumber& phoneNumber);
		friend std::istream& operator>>(std::istream& in, PhoneNumber& phoneNumber);
	};

	friend std::ostream& operator<<(std::ostream& out, const PhoneNumber& phoneNumber);
	friend std::istream& operator>>(std::istream& in, PhoneNumber& phoneNumber);

	//bool compNames(const std::pair<Person, PhoneNumber>& firstContact, const std::pair<Person, PhoneNumber>& secondContact);
	//bool compPhones(const std::pair<Person, PhoneNumber>& firstContact, const std::pair<Person, PhoneNumber>& secondContact);

	std::vector<std::pair<Person, PhoneNumber>> contacts;
	
public:
	PhoneBook(std::ifstream& file);
	friend std::ostream& operator<<(std::ostream& out, const PhoneBook book);

	//void sortByName();
	//void sortByPhone();
	//bool findPerson(const std::pair<Person, PhoneNumber>& contact);
	//void changePhoneNumber(Person& person, PhoneNumber& phoneNumber);
};

