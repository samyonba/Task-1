#pragma once
#include <iostream>
#include <string>
#include <optional>
#include <functional>
#include <iomanip>
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
		Person(std::string surname, std::string name, std::optional<std::string> patronymic);
		bool operator<(const Person& p);
		bool operator>(const Person& p);
		bool operator==(const Person& p);
		friend std::ostream& operator<<(std::ostream &out, const Person &person);
	};

	friend std::ostream& operator<<(std::ostream &out, const Person &person);

	struct PhoneNumber
	{
	private:
		int countryId;
		int cityId;
		std::string number;
		std::optional<int> extension;
	public:
		bool operator<(const PhoneNumber& phone);
		bool operator>(const PhoneNumber& phone);
		bool operator==(const PhoneNumber& phone);
		friend std::ostream& operator<<(std::ostream& out, const PhoneNumber& phoneNumber);
	};

	friend std::ostream& operator<<(std::ostream& out, const PhoneNumber& phoneNumber);

public:
	//std::pair<PhoneBook::Person, PhoneBook::PhoneNumber> person_number;
	Person person{"Surn", "Nam", "Pat"}; //Test object
};

