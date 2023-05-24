/*
������� 2.
�������� ���������� ����������� �����. ����������
������� ������ �� �������� (���, �������� �������,
������� �������, ��������� �������, ��������������
���������� � ��������) ������ ���������������� ������.
��������� ����� �����������-�������, ���������-�������, 
��������������, inline-���������-�������,
����������� ��������������, ���������� ����������.
����������� ���������� �������� ����������� ������ ���
���. ������������ ������������ ����������� ���������
����� ���������, ������� ���������, ������ ���������
�� ���, ���������� ���� ���������.
*/

#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>

const char filename[] = "phonebook.txt";

class PhoneInfo {
private: 
	std::string _name;
	std::string _surname;
	std::string _patronymic;
	std::string _homePhoneNumber;
	std::string _mobilePhoneNumber;
	std::string _workPhoneNumber;
	std::string _additionalInfo;

public:
	PhoneInfo() :	_name(""), _surname(""), _patronymic(""),
					_homePhoneNumber(""), _mobilePhoneNumber(""),
					_workPhoneNumber(""), _additionalInfo("")
	{}

	PhoneInfo(std::string name, std::string surname, std::string patronymic,
				std::string homePhoneNumber, std::string mobilePhoneNumber,
				std::string workPhoneNumber, std::string additionalInfo) : _name(name), _surname(surname), _patronymic(patronymic),
																			_homePhoneNumber(homePhoneNumber), _mobilePhoneNumber(mobilePhoneNumber),
																			_workPhoneNumber(workPhoneNumber), _additionalInfo(additionalInfo)
	{}

	std::string GetName() const {
		return _name;
	}

	std::string GetSurname() const {
		return _surname;
	}

	std::string GetPatronimic() const {
		return _patronymic;
	}

	std::string GetHomePhoneNumber() const {
		return _homePhoneNumber;
	}

	std::string GetMobilePhoneNumber() const {
		return _mobilePhoneNumber;
	}

	std::string GetWorkPhoneNumber() const {
		return _workPhoneNumber;
	}

	std::string GetAdditionalInfo() const {
		return _additionalInfo;
	}

	void Print() const;

};

class PhoneBook {
private:
	std::vector<PhoneInfo*> phoneBook;

public:
	PhoneBook() {
		phoneBook;
	}
	PhoneBook(std::vector<PhoneInfo*>& book) {
		phoneBook = book;
	}

	void addPhoneToBook();

	void Print();

	void EraseRecord(int numRec);

	int Size() const {
		return (int)phoneBook.size();
	}

	bool ReadFromFile();

	bool WriteTofile();

	void SearcBySNP(std::string& str);

	~PhoneBook() {
		for (int i = 0; i < phoneBook.size(); ++i) {
			delete phoneBook.at(i);
			//std::cout << "����������� ������ ��� " << i << " ������ �� ������� phoneBook.\n";
		}
		//std::cout << "��������� ����������\n";
	}

};

int menu() {
	static int n;
	do {
		system("cls");
		std::cout << "��������� \"���������� �����\"\n";
		std::cout << "1. �������� ������ � ���������� �����.\n";
		std::cout << "2. ������� ���������� ����� �� �����.\n";
		std::cout << "3. ������� ������.\n";
		std::cout << "4. ����� ������.\n";
		std::cout << "5. ����� �� ���������.\n";
		std::cout << "������� ����� -> ";
		std::cin >> n;
	} while (n < 1 || n > 5);
	return n;
}



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 
	PhoneBook phoneBook;
	if (phoneBook.ReadFromFile() == false) {	// ������ ���������� ����� �� �����
		std::cout << "������ ������ �� �����.\n";
		system("cls");
	}
	
	int choice = 0;
	do {
		choice = menu();
		if (choice == 1) { // ���������� ������ � ���������� �����
			phoneBook.addPhoneToBook();
		}
		else if (choice == 2) {	// ����� �� ����� ���������� �����
			system("cls");
			phoneBook.Print();
			system("pause");
		}
		else if (choice == 3) {	// �������� ������ �� ���������� �����
			system("cls");
			phoneBook.Print();
			int numRec = 0;
			do {
				std::cout << "������� ����� ������ ��� �������� (����� � ���� - " << phoneBook.Size()+1 << ")" << " -> ";
				std::cin >> numRec;
			} while (numRec < 1 || numRec > phoneBook.Size() + 1);
			if (numRec == phoneBook.Size() + 1)
				continue;
			phoneBook.EraseRecord(numRec - 1);
		}
		else if (choice == 4) {	// ����� �� �������, ����� ��� ��������
			std::string str;
			std::cout << "������� ������� ��� ��� ��� �������� -> ";
			std::cin.ignore();
			std::getline(std::cin, str);
			phoneBook.SearcBySNP(str);
			system("pause");
		}

	} while (choice != 5);

	if (phoneBook.WriteTofile() == false) { // ������ ���������� ����� � ����
		std::cout << "������ ������ � ����.\n";
	}

	return 0;
}


void PhoneInfo::Print() const {
	std::cout << _surname << ' ' << _name << ' ' << _patronymic << std::endl;
	std::cout << "�������� �������: " << _homePhoneNumber << std::endl;
	std::cout << "������� �������: " << _workPhoneNumber << std::endl;
	std::cout << "��������� �������: " << _mobilePhoneNumber << std::endl;
	std::cout << "�������������� ����������: " << _additionalInfo << "\n\n";
}

void PhoneBook::addPhoneToBook() {

	std::string name;
	std::string surname;
	std::string patronymic;
	std::string homePhoneNumber;
	std::string mobilePhoneNumber;
	std::string workPhoneNumber;
	std::string additionalInfo;

	std::cout << "������� ������� �������� -> ";
	std::cin.ignore();
	std::getline(std::cin, surname);
	std::cout << "������� ��� �������� -> ";
	std::getline(std::cin, name);
	std::cout << "������� �������� �������� -> ";
	std::getline(std::cin, patronymic);
	std::cout << "������� ����� ��������� �������� -> ";
	std::getline(std::cin, homePhoneNumber);
	std::cout << "������� ����� �������� �������� -> ";
	std::getline(std::cin, workPhoneNumber);
	std::cout << "������� ����� ���������� �������� -> ";
	std::getline(std::cin, mobilePhoneNumber);
	std::cout << "������� �������������� ���������� -> ";
	std::getline(std::cin, additionalInfo);
	PhoneInfo* p_tmp = new PhoneInfo(name, surname, patronymic, homePhoneNumber, mobilePhoneNumber, workPhoneNumber, additionalInfo);
	phoneBook.push_back(p_tmp);
}

void PhoneBook::Print() {
	std::vector<PhoneInfo*>::iterator it;
	int count = 1;
	for (it = phoneBook.begin(); it != phoneBook.end(); ++it) {
		std::cout << "������ �" << count << std::endl;
		(*it)->Print();
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

void PhoneBook::SearcBySNP(std::string& str) {
	std::vector<PhoneInfo*>::iterator it;
	for (it = phoneBook.begin(); it != phoneBook.end(); ++it) {
		if (str == (*it)->GetName() || str == (*it)->GetSurname() || str == (*it)->GetPatronimic()) {
			(*it)->Print();
		}
	}
}

