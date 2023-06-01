#ifndef _PHONE_BOOK_HPP_
#define _PHONE_BOOK_HPP_
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "phone_info.hpp"

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

	void Print() const;

	void EraseRecord(int numRec);

	int Size() const {
		return (int)phoneBook.size();
	}

	bool ReadFromFile();

	bool WriteTofile();

	void SearcBySNP(std::string& str) const;

	~PhoneBook() {
		for (int i = 0; i < phoneBook.size(); ++i) {
			delete phoneBook.at(i);
			//std::cout << "Освобождена память для " << i << " записи из вектора phoneBook.\n";
		}
		//std::cout << "Отработал деструктор\n";
	}

};


#endif 
