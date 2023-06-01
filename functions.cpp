#include "functions.hpp"


int menu() {
	static int n;
	do {
		system("cls");
		std::cout << "Программа \"Телефонная книга\"\n";
		std::cout << "1. Добавить запись в телефонную книгу.\n";
		std::cout << "2. Вывести телефонную книгу на экран.\n";
		std::cout << "3. Удалить запись.\n";
		std::cout << "4. Найти запись.\n";
		std::cout << "5. Выход из программы.\n";
		std::cout << "Введите номер -> ";
		std::cin >> n;
	} while (n < 1 || n > 5);
	return n;
}
