#include "phone_book.hpp"
#include "phone_info.hpp"
#include "functions.hpp"

void PhoneBook::addPhoneToBook() {

	std::string name;
	std::string surname;
	std::string patronymic;
	std::string homePhoneNumber;
	std::string mobilePhoneNumber;
	std::string workPhoneNumber;
	std::string additionalInfo;

	std::cout << "Введите Фамилию абонента -> ";
	std::cin.ignore();
	std::getline(std::cin, surname);
	std::cout << "Введите имя абонента -> ";
	std::getline(std::cin, name);
	std::cout << "Введите отчество абонента -> ";
	std::getline(std::cin, patronymic);
	std::cout << "Введите номер домашнего телефона -> ";
	std::getline(std::cin, homePhoneNumber);
	std::cout << "Введите номер рабочего телефона -> ";
	std::getline(std::cin, workPhoneNumber);
	std::cout << "Введите номер мобильного телефона -> ";
	std::getline(std::cin, mobilePhoneNumber);
	std::cout << "Введите дополнительную информацию -> ";
	std::getline(std::cin, additionalInfo);
	PhoneInfo* p_tmp = new PhoneInfo(name, surname, patronymic, homePhoneNumber, mobilePhoneNumber, workPhoneNumber, additionalInfo);
	phoneBook.push_back(p_tmp);
}

void PhoneBook::Print() const {
	std::vector<PhoneInfo*>::iterator it;
	int count = 1;
	for (const auto it : phoneBook) {
		std::cout << "Запись №" << count << std::endl;
		it->Print();
		count++;
	}
}

void PhoneBook::EraseRecord(int numRec) {
	if (numRec < 0 || numRec > phoneBook.size() - 1)
		return;
	delete phoneBook.at(numRec);
	phoneBook.erase(phoneBook.begin() + numRec);
	return;
}

bool PhoneBook::ReadFromFile() {
	std::ifstream fin;

	fin.open(filename);
	if (fin.is_open()) {
		static std::string name;
		static std::string surname;
		static std::string patronymic;
		static std::string homePhoneNumber;
		static std::string mobilePhoneNumber;
		static std::string workPhoneNumber;
		static std::string additionalInfo;
		while (!fin.eof()) {
			std::getline(fin, name); if (fin.eof()) break;
			std::getline(fin, surname); if (fin.eof()) break;
			std::getline(fin, patronymic); if (fin.eof()) break;
			std::getline(fin, homePhoneNumber); if (fin.eof()) break;
			std::getline(fin, workPhoneNumber); if (fin.eof()) break;
			std::getline(fin, mobilePhoneNumber); if (fin.eof()) break;
			std::getline(fin, additionalInfo); if (fin.eof()) break;
			PhoneInfo* p_tmp = new PhoneInfo(name, surname, patronymic, homePhoneNumber, mobilePhoneNumber, workPhoneNumber, additionalInfo);
			phoneBook.push_back(p_tmp);
			name = ""; surname = ""; patronymic = ""; homePhoneNumber = ""; mobilePhoneNumber = ""; workPhoneNumber = ""; additionalInfo = "";
		}

		fin.close();
		return true;
	}
	return false;
}

bool PhoneBook::WriteTofile() {
	std::ofstream fout;
	fout.open(filename);
	if (fout.is_open()) {
		std::vector<PhoneInfo*>::iterator it;
		for (it = phoneBook.begin(); it != phoneBook.end(); ++it) {
			fout << (*it)->GetName() << '\n';
			fout << (*it)->GetSurname() << '\n';
			fout << (*it)->GetPatronimic() << '\n';
			fout << (*it)->GetHomePhoneNumber() << '\n';
			fout << (*it)->GetWorkPhoneNumber() << '\n';
			fout << (*it)->GetMobilePhoneNumber() << '\n';
			fout << (*it)->GetAdditionalInfo() << '\n';
		}
		fout.close();
		return true;
	}
	return false;
}

void PhoneBook::SearcBySNP(std::string& str) const {
	std::vector<PhoneInfo*>::iterator it;
	for (const auto it : phoneBook) {
		if (str == it->GetName() || str == it->GetSurname() || str == it->GetPatronimic()) {
			it->Print();
		}
	}
}
