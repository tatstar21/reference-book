#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "ReferenceBook.h"
#include "ReferenceBookManager.cpp"

int main()
{
    setlocale(LC_ALL, "Russian");

	std::cout << "\nC���������:\n";
	std::cout << "�������� ����� ����:\n";
	std::cout <<
		"1 - ����� �� ��������;\n"
		"2 - ����� �� ���������;\n"
		"3 - ����� �� ������ ��������;\n"
		"4 - ����� �� ���� ������������;\n"
		"5 - ����� ���� �������;\n"
		"6 - �������� ������ � ���������;\n"
		"0 - �����;\n";

	int menuItem;
	std::cout << "������� ����� ����: ";
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
			std::cout << "\n����� �� ��������:\n";
			std::cout << "������� �������� ��������:\n";
			std::getline(std::cin, companyName);
			search(companies, companyName, namePredicate);
			break;

		case 2:
			std::cout << "\n����� �� ���������:\n";
			std::cout << "������� ���������:\n";
			std::getline(std::cin, owner);
			search(companies, owner, ownerPredicate);
			break;

		case 3:
			std::cout << "\n����� �� ������ ��������:\n";
			std::cout << "������� �������:\n";
			std::getline(std::cin, telephone);
			search(companies, telephone, telephonePredicate);
			break;

		case 4:
			std::cout << "\n����� �� ���� ������������:\n";
			std::cout << "������� ��� ������������:\n";
			std::getline(std::cin, activity);
			search(companies, activity, activityPredicate);
			break;

		case 5:
			std::cout << "\n����� ���� �������:\n";
			printAll(companies);
			break;

		case 6:
			std::cout << "\n�������� ������:\n";
			addNewCompany(companies);
			saveCompanies(path, companies);
			
		default:
			std::cout << "\n�����\n";
			break;
		}
		delete companies;
	}
		
		
	catch (const std::exception& ex)
	{
		std::cerr << ex.what();
	}
}

