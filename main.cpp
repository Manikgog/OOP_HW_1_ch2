/*
Задание 2.
Создайте приложение «Телефонная книга». Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего класса.
Наполните класс переменными-членами, функциями-членами, 
конструкторами, inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память под
ФИО. Предоставьте пользователю возможность добавлять
новых абонентов, удалять абонентов, искать абонентов
по ФИО, показывать всех абонентов.
*/

#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include "functions.hpp"
#include "phone_book.hpp"
#include "phone_info.hpp"


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 
	PhoneBook phoneBook;
	if (phoneBook.ReadFromFile() == false) {	// чтение телефонной книги из файла
		std::cout << "Ошибка чтения из файла.\n";
		system("cls");
	}
	
	int choice = 0;
	do {
		choice = menu();
		if (choice == 1) { // добавление записи в телефонную книгу
			phoneBook.addPhoneToBook();
		}
		else if (choice == 2) {	// вывод на экран телефонной книги
			system("cls");
			phoneBook.Print();
			system("pause");
		}
		else if (choice == 3) {	// удаление записи из телефонной книги
			system("cls");
			phoneBook.Print();
			int numRec = 0;
			do {
				std::cout << "Введите номер записи для удаления (Выход в меню - " << phoneBook.Size()+1 << ")" << " -> ";
				std::cin >> numRec;
			} while (numRec < 1 || numRec > phoneBook.Size() + 1);
			if (numRec == phoneBook.Size() + 1)
				continue;
			phoneBook.EraseRecord(numRec - 1);
		}
		else if (choice == 4) {	// поиск по фамилии, имени или отчеству
			std::string str;
			std::cout << "Введите фамилию или имя или отчество -> ";
			std::cin.ignore();
			std::getline(std::cin, str);
			phoneBook.SearcBySNP(str);
			system("pause");
		}

	} while (choice != 5);

	if (phoneBook.WriteTofile() == false) { // запись телефонной книги в файл
		std::cout << "Ошибка записи в файл.\n";
	}

	return 0;
}


