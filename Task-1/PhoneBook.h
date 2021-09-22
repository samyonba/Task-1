#pragma once
#include <iostream>
#include <string>
#include <optional>
#include <functional>
#include <iomanip>
class PhoneBook
{
public:
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


	Person person{"Surn", "Nam", "Pat"};
};

