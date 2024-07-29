#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "ReferenceBook.h"
#include "ReferenceBookManager.cpp"

int main()
{
    setlocale(LC_ALL, "Russian");

	std::cout << "\nCПРАВОЧНИК:\n";
	std::cout << "Выберете пункт меню:\n";
	std::cout <<
		"1 - Поиск по названию;\n"
		"2 - Поиск по владельцу;\n"
		"3 - Поиск по номеру телефона;\n"
		"4 - Поиск по роду деятельности;\n"
		"5 - Показ всех записей;\n"
		"6 - Добавить запись и сохранить;\n"
		"0 - выход;\n";

	int menuItem;
	std::cout << "Введите пункт меню: ";
	std::cin >> menuItem;
	std::cin.ignore();

	try
	{
		std::string path = "company.txt";
		std::vector <ReferenceBook*>* companies = loadCompanies(path);
		std::string companyName;
		std::string owner;
		std::string telephone;
		std::string activity;

		switch (menuItem)
		{
		case 1:
			std::cout << "\nПоиск по названию:\n";
			std::cout << "Введите название компании:\n";
			std::getline(std::cin, companyName);
			search(companies, companyName, namePredicate);
			break;

		case 2:
			std::cout << "\nПоиск по владельцу:\n";
			std::cout << "Введите владельца:\n";
			std::getline(std::cin, owner);
			search(companies, owner, ownerPredicate);
			break;

		case 3:
			std::cout << "\nПоиск по номеру телефона:\n";
			std::cout << "Введите телефон:\n";
			std::getline(std::cin, telephone);
			search(companies, telephone, telephonePredicate);
			break;

		case 4:
			std::cout << "\nПоиск по роду деятельности:\n";
			std::cout << "Введите род деятельности:\n";
			std::getline(std::cin, activity);
			search(companies, activity, activityPredicate);
			break;

		case 5:
			std::cout << "\nПоказ всех записей:\n";
			printAll(companies);
			break;

		case 6:
			std::cout << "\nДобавить запись:\n";
			addNewCompany(companies);
			saveCompanies(path, companies);
			
		default:
			std::cout << "\nВыход\n";
			break;
		}
		delete companies;
	}
		
		
	catch (const std::exception& ex)
	{
		std::cerr << ex.what();
	}
}

