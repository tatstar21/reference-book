#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "ReferenceBook.h"


ReferenceBook::ReferenceBook(std::string companyName, std::string owner,
	std::string telephone, std::string address,
	std::string typeOfActivity)
{
	companyName_ = companyName;
	owner_ = owner;
	telephone_ = telephone;
	address_ = address;
	typeOfActivity_ = typeOfActivity;
}

void ReferenceBook::printCompany()
{
	std::cout << "\n**************************\n";
	std::cout << "Название фирмы: " << companyName_ << '\n';
	std::cout << "Владелец: " << owner_ << '\n';
	std::cout << "Телефон: " << telephone_ << '\n';
	std::cout << "Адрес: " << address_ << '\n';
	std::cout << "Род деятельности: " << typeOfActivity_ << '\n';
}

void ReferenceBook::save(std::ostream& ofstream)
{
	ofstream << companyName_ << ' '
		<< owner_ << ' ' << telephone_ << ' '
		<< address_ << ' ' << typeOfActivity_ << std::endl;
}

void ReferenceBook::load(std::istream& ifstream)
{
	ifstream >> companyName_ >> owner_ >> telephone_
		>> address_ >> typeOfActivity_ ;
}








