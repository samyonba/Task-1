#pragma once
#include <iostream>
#include <string>
#include <optional>
#include <functional>
class PhoneBook
{
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
	};
};

