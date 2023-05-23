/*
������� 2.
�������� ���������� ����������� �����. ����������
������� ������ �� �������� (���, �������� �������,
������� �������, ��������� �������, ��������������
���������� � ��������) ������ ���������������� ������.
��������� ����� �����������-�������, ����������������, 
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

class phoneInfo {
private: 
	std::string _name;
	std::string _surname;
	std::string _patronymic;
	std::string _homePhoneNumber;
	std::string _mobilePhoneNumber;
	std::string _workPhoneNumber;
	std::string _additionalInfo;

public:
	phoneInfo() :	_name(""), _surname(""), _patronymic(""),
					_homePhoneNumber(""), _mobilePhoneNumber(""),
					_workPhoneNumber(""), _additionalInfo("")
	{}

	phoneInfo(std::string name, std::string surname, std::string patronymic,
				std::string homePhoneNumber, std::string mobilePhoneNumber,
				std::string workPhoneNumber, std::string additionalInfo) : _name(name), _surname(surname), _patronymic(patronymic),
																			_homePhoneNumber(homePhoneNumber), _mobilePhoneNumber(mobilePhoneNumber),
																			_workPhoneNumber(workPhoneNumber), _additionalInfo(additionalInfo)
	{}

	std::string GetName() {
		return _name;
	}

	std::string GetSurname() {
		return _surname;
	}

	std::string GetPatronimic() {
		return _patronymic;
	}

	std::string GetHomePhoneNumber() {
		return _homePhoneNumber;
	}

	std::string GetMobilePhoneNumber() {
		return _mobilePhoneNumber;
	}

	std::string GetWorkPhoneNumber() {
		return _workPhoneNumber;
	}

	std::string GetAdditionalInfo() {
		return _additionalInfo;
	}

	void Print() {
		std::cout << _surname << ' ' << _name << ' ' << _patronymic << std::endl;
		std::cout << "�������� �������: " << _homePhoneNumber << std::endl;
		std::cout << "������� �������: " << _workPhoneNumber << std::endl;
		std::cout << "��������� �������: " << _mobilePhoneNumber << std::endl;
		std::cout << "�������������� ����������: " << _additionalInfo << "\n\n";
	}

};

class PhoneBook {
private:
	std::vector<phoneInfo> phoneBook;

public:
	PhoneBook() {
		phoneBook;
	}
	PhoneBook(std::vector<phoneInfo> book) {
		phoneBook = book;
	}

	void addPhoneToBook() {

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
		phoneInfo tmp(name, surname, patronymic, homePhoneNumber, mobilePhoneNumber, workPhoneNumber, additionalInfo);
		phoneBook.push_back(tmp);
	}

	void Print() {
		std::vector<phoneInfo>::iterator it;
		int count = 1;
		for (it = phoneBook.begin(); it != phoneBook.end(); ++it) {
			std::cout << "������ �" << count << std::endl;
			it->Print();
			count++;
		}
	}

	
	void EraseRecord(int numRec) {
		if (numRec < 0 || numRec > phoneBook.size() - 1)
			return;
		phoneBook.erase(phoneBook.begin() + numRec);
		return;
	}

	int Size() {
		return phoneBook.size();
	}

	bool ReadFromFile() {
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
				phoneInfo tmp(name, surname, patronymic, homePhoneNumber, mobilePhoneNumber, workPhoneNumber, additionalInfo);
				phoneBook.push_back(tmp);
				name = ""; surname = ""; patronymic = ""; homePhoneNumber = ""; mobilePhoneNumber = ""; workPhoneNumber = ""; additionalInfo = "";
			}

			fin.close();
			return true;
		}
		return false;
	}

	bool WriteTofile() {
		std::ofstream fout;
		fout.open(filename);
		if (fout.is_open()) {
			std::vector<phoneInfo>::iterator it;
			for (it = phoneBook.begin(); it != phoneBook.end(); ++it) {
				fout << it->GetName() << '\n';
				fout << it->GetSurname() << '\n';
				fout << it->GetPatronimic() << '\n';
				fout << it->GetHomePhoneNumber() << '\n';
				fout << it->GetWorkPhoneNumber() << '\n';
				fout << it->GetMobilePhoneNumber() << '\n';
				fout << it->GetAdditionalInfo() << '\n';
			}
			fout.close();
			return true;
		}
		return false;
	}

	void SearcBySNP(std::string& str) {
		std::vector<phoneInfo>::iterator it;
		for (it = phoneBook.begin(); it != phoneBook.end(); ++it) {
			if (str == it->GetName() || str == it->GetSurname() || str == it->GetPatronimic()) {
				it->Print();
			}
		}
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
	if (phoneBook.ReadFromFile() == false) {
		std::cout << "������ ������ �� �����.\n";
		system("cls");
	}
	
	int choice = 0;
	do {
		choice = menu();
		if (choice == 1) {
			phoneBook.addPhoneToBook();
		}
		else if (choice == 2) {
			phoneBook.Print();
			system("pause");
		}
		else if (choice == 3) {
			phoneBook.Print();
			int numRec = 0;
			do {
				std::cout << "������� ����� ������ ��� �������� -> ";
				std::cin >> numRec;
			} while (numRec < 1 || numRec > phoneBook.Size());
			phoneBook.EraseRecord(numRec - 1);
		}
		else if (choice == 4) {
			std::string str;
			std::cout << "������� ������� ��� ��� ��� �������� -> ";
			std::cin.ignore();
			std::getline(std::cin, str);
			phoneBook.SearcBySNP(str);
			system("pause");
		}

	} while (choice != 5);

	if (phoneBook.WriteTofile() == false) {
		std::cout << "������ ������ � ����.\n";
	}

	return 0;
}
