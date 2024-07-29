#pragma once
#include <string>
#include <fstream>
#include <iostream>

class ReferenceBook
{
public:
	ReferenceBook(){}
	ReferenceBook(std::string companyName, std::string owner,
		std::string telephone, std::string address, 
		std::string typeOfactivity);

	void save(std::ostream& ofstream);
	void load(std::istream& ifstream);
	void printCompany();

	std::string getName();
	std::string getOwner();
	std::string getTelephone();
	std::string getAddress();
	std::string getTypeOfActivity();

private:
	std::string companyName_;
	std::string owner_;
	std::string telephone_;
	std::string address_;
	std::string typeOfActivity_;
};

inline std::string ReferenceBook::getName() {
	return companyName_;
}

inline std::string ReferenceBook::getOwner() {
	return owner_;
}

inline std::string ReferenceBook::getTelephone() {
	return telephone_;
}

inline std::string ReferenceBook::getAddress() {
	return address_;
}

inline std::string ReferenceBook::getTypeOfActivity() {
	return typeOfActivity_;
}
