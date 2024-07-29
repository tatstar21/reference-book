#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "ReferenceBook.h"

static bool namePredicate(ReferenceBook* company, std::string nameCompany)
{
	return company->getName() == nameCompany;
}

static bool ownerPredicate(ReferenceBook* company, std::string owner)
{
	return company->getOwner() == owner;
}

static bool telephonePredicate(ReferenceBook* company, std::string telephone)
{
	return company->getTelephone() == telephone;
}

static bool activityPredicate(ReferenceBook* company, std::string activity)
{
	return company->getTypeOfActivity() == activity;
}

static void addNewCompany(std::vector <ReferenceBook*>* companies)
{
	int n;
	std::cout << "Сколько компаний вы хотите добавить:\n";
	std::cin >> n;
	std::cin.ignore();

	for (int ii = 0; ii < n; ii++)
	{
		std::cout << "Введите название компании:\n";
		std::string companyName;
		std::getline(std::cin, companyName);

		std::cout << "Введите владельца:\n";
		std::string owner;
		std::getline(std::cin, owner);

		std::cout << "Введите телефон:\n";
		std::string  telephone;
		std::getline(std::cin, telephone);

		std::cout << "Введите адрес:\n";
		std::string  address;
		std::getline(std::cin, address);

		std::cout << "Введите род деятельности:\n";
		std::string typeOfActivity;
		std::getline(std::cin, typeOfActivity);

		ReferenceBook* newCompany = new ReferenceBook(companyName, owner,
			telephone, address, typeOfActivity);
		companies->push_back(newCompany);
	}
}

static int countLineOfFile(std::string path)
{
	std::ifstream inFile(path);
	auto size = std::count(std::istreambuf_iterator<char>(inFile),
		std::istreambuf_iterator<char>(), '\n');

	int count = size;
	inFile.close();

	return count;
}

static void saveCompanies(std::string path, std::vector <ReferenceBook*>* companies)
{
	std::ofstream outFile(path);

	for (int ii = 0; ii < companies->size(); ii++) {
		(*companies)[ii]->save(outFile);
	}
	outFile.close();
}

static std::vector <ReferenceBook*>* loadCompanies(std::string path)
{
	std::vector <ReferenceBook*>* companies = new std::vector <ReferenceBook*>;

	int n = countLineOfFile(path);

	std::ifstream inFile(path);

	for (int ii = 0; ii < n; ii++)
	{
		ReferenceBook* company = new ReferenceBook;
		company->load(inFile);
		companies->push_back(company);
	}

	inFile.close();
	return companies;
}

static void printAll(std::vector <ReferenceBook*>* companies)
{
	for (int ii = 0; ii < companies->size(); ii++) {
		(*companies)[ii]->printCompany();
	}
}

static void search(std::vector <ReferenceBook*>* companies, std::string field, bool(predicate)(ReferenceBook* company, std::string))//?
{
	bool isFound = false;

	for (int ii = 0; ii < companies->size(); ii++) {
		if (predicate((*companies)[ii], field)) {
			isFound = true;
			(*companies)[ii]->printCompany();
		}
	}

	if (isFound == false) {
		std::cout << "В справочнике компания по вашим данным не найдена!\n";
		return;
	}
}
